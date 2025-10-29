#include <Siv3D.hpp>

#include "../Game.h"
#include "GameScene.h"
#include "../Actor/DirtTile.h"
#include "../Constants.h"
#include "../Component/SpriteComponent.h"

using namespace Constants;
using namespace SinGame;

GameScene::GameScene(const InitData& init)
	:IScene{ init }
{
	double Tilenum = 20;
	double TileSize = 1080 / Tilenum;
	double scale = TileSize / 32;
	
	mTileGrid = Grid<Actor*>(Tilenum, 5);

	// Game::getGame() はインスタンスメソッドなので、Gameオブジェクトが必要
	// 共有データからGameインスタンスを取得する
	for (int i = 0; i < Tilenum; i++)
	{

		DirtTile* dirtTile = new DirtTile(Game::Instance());
		Logger << U"createDirtTitle";
		dirtTile->SetPosition(Vec2(400.0f + i * TileSize, 300.0f));
		dirtTile->SetScale(scale);
		mTileGrid[Point{ i, 0 }] = dirtTile;
	}
	
}

void GameScene::update()
{
	for (auto sprite : Game::Instance()->GetSprites())
	{
		sprite->Draw();
	}
}
