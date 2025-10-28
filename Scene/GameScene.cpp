#include <Siv3D.hpp>

#include "../Game.h"
#include "GameScene.h"
#include "../Actor/DirtTile.h"

using namespace SinGame;

GameScene::GameScene(const InitData& init)
	:IScene{ init }
{
	// Game::getGame() はインスタンスメソッドなので、Gameオブジェクトが必要
	// 共有データからGameインスタンスを取得する
	DirtTile* dirtTile = new DirtTile(Game::Instance());
	dirtTile->SetPosition(Vec2(400.0f, 300.0f));
}

void GameScene::update()
{
	
}
