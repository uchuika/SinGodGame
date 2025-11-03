#include <Siv3D.hpp>

#include "TitleScene.h"
#include "../Game.h"

using namespace SinGame;

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game) : AbstractScene(impl, parameter, game)
, mGame(game)
{

}

void TitleScene::update()
{
	if (KeyZ.down())
	{

		Parameter parameter;
		_implSceneChanged->onSceneChanged(EScene::Game,parameter, false);
	}
}

void TitleScene::draw() const
{
}

void TitleScene::drawUI()
{
	font(U"タイトルシーン").drawAt(960, 540);
}

EScene TitleScene::GetScene() const
{
	return EScene::Title;
}
