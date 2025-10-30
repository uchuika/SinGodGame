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
	// Game::Instance() でシングルトンインスタンスを取得し、GetTextureでテクスチャを取得
	// 戻り値の型は auto で推論
	Texture texture = Game::Instance()->GetTexture("example/windmill.png");
	// テクスチャを描画
	texture.scaled(camera.getTargetScale()).drawAt(camera.getCenter().x, camera.getCenter().y);

	Print << U"Camera Scale: " << camera.getScale();
}
