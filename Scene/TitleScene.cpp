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

}

void TitleScene::draw() const
{
}

void TitleScene::drawUI() const
{
}

EScene TitleScene::GetScene() const
{
	return EScene::Title;
}
