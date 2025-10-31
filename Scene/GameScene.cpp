#include <Siv3D.hpp>

#include "../Game.h"
#include "GameScene.h"
#include "../Actor/DirtTile.h"
#include "../Constants.h"
#include "../Component/SpriteComponent.h"

using namespace SinGame;

/*
using namespace Constants;
using namespace SinGame;

GameScene::GameScene(const InitData& init)
	:IScene{ init }
{
	double Tilenum = 20;
	double TileHeightNum = 10;
	double TileSize = 1080 / Tilenum;
	double scale = TileSize / 32;
	
	mTileGrid = Grid<Actor*>((int)Tilenum, (int)TileHeightNum);

	// Game::getGame() はインスタンスメソッドなので、Gameオブジェクトが必要
	// 共有データからGameインスタンスを取得する
	for (int i = 0; i < Tilenum; i++)
	{
		for (int j = 0; j < TileHeightNum; j++) {
			DirtTile* dirtTile = new DirtTile(Game::Instance());
			Logger << U"createDirtTitle";
			dirtTile->SetPosition(Vec2(400.0f + i * (float)TileSize, 300.0f + j * (float)TileSize));
			dirtTile->SetScale((float)scale);
			mTileGrid[Point{ i, j }] = dirtTile;
		}
	}
	
}

void GameScene::update()
{
	for (auto sprite : Game::Instance()->GetSprites())
	{
		sprite->Draw();
	}
	drawUI();
}

void GameScene::drawUI() const
{
	Camera2D camera = Game::Instance()->GetCamera();
	//Logger << U"drawUI";
	Texture texture = Game::Instance()->GetTexture("example/windmill.png");
	// テクスチャを描画
	texture.scaled(camera.getTargetScale()).drawAt(camera.getCenter().x, camera.getCenter().y);

	Print << U"Camera Scale: " << camera.getScale();
}*/
const char* GameScene::ParameterTagStage = "ParameterTagStage";	//パラメータのタグ「ステージ」
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";	//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game) : AbstractScene(impl, parameter, game)
, mGame(game)
, mCount(0)
{
	_level = parameter.get(ParameterTagLevel);

	double Tilenum = 20;
	double TileHeightNum = 10;
	double TileSize = 1080 / Tilenum;
	double scale = TileSize / 32;

	mTileGrid = Grid<Actor*>((int)Tilenum, (int)TileHeightNum);


	for (int i = 0; i < Tilenum; i++) {
		for (int j = 0; j < TileHeightNum; j++) {
			DirtTile* dirtTile = new DirtTile(mGame);
			dirtTile->SetPosition(Vec2(400.0f + i * (float)TileSize, 300.0f + j * (float)TileSize));
			dirtTile->SetScale((float)scale);
			mTileGrid[Point{ i, j }] = dirtTile;
		}
	}

	
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
