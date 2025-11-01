#include <Siv3D.hpp>

#include "../Game.h"
#include "GameScene.h"
#include "../Actor/DirtTile.h"
#include "../Actor/Tile.h"
#include "../Map/GridTexture.h"
#include "../Map/MapGrid.h"
#include "../Constants.h"
#include "../Component/SpriteComponent.h"


using namespace SinGame;

const char* GameScene::ParameterTagStage = "ParameterTagStage";	//パラメータのタグ「ステージ」
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";	//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game) : AbstractScene(impl, parameter, game)
, mGame(game)
, mCount(0)
{
	_level = parameter.get(ParameterTagLevel);

	GridTexture gridTexture = GridTexture(Image{ U"Assets/Outside_A2.png" });

	//マップ生成
	MapGrid grid = MapGrid(game, 20, 20, gridTexture);
}

void GameScene::update()
{
	sprites = mGame->GetSprites();

}

void GameScene::draw() const
{
	Camera2D camera = mGame->GetCamera();
	const auto t = camera.createTransformer();

	for(SpriteComponent* sprite : sprites)
	{
		sprite->Draw();
	}
}

void GameScene::drawUI() const
{
	font(U"test").draw(0, 0);
}

EScene GameScene::GetScene() const
{
	return EScene::Game;
}
