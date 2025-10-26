// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Game.h"
#include "Actor/Actor.h"
#include "Actor/DirtTile.h"
#include "Component/SpriteComponent.h"

using namespace SinGame;

Game::Game()
{

}

bool Game::Inisitalize()
{
	//シーンマネージャーの宣言
	SceneManager<String> sceneManager;
	/*
#if _DEBUG
	sceneManager.add<>
	
#endif
	*/
	LoadData();
	return true;
}

//タスクを順番に実行
void Game::RunLoop()
{
	ProcessInput();
	UpdateGame();
	GenerateOutput();
}

/*
//フローチャート作成
void Game::DoChart()
{

}
*/

//インプットの処理
void Game::ProcessInput()
{
}

//ゲームの様々な更新処理
void Game::UpdateGame()
{
	mUpdatingActors = true;
	for(auto actor : mActors)
	{
		actor->Update(Scene::DeltaTime());
	}
	mUpdatingActors = false;

	//保留中のアクターをアクターに移動する
	for (auto pending : mPendingActors)
	{
		mActors.emplace_back(pending);
	}
	mPendingActors.clear();

	//deadActorを一時的に配列に追加する
	Array<Actor*> deadActors;
	for (auto actor : mActors)
	{
		if (actor->GetState() == Actor::EDead)
		{
			deadActors.emplace_back(actor);
		}
	}

	//deadActorを削除する（これによりアクターから削除される）
	for (auto actor : deadActors)
	{
		delete actor;
	}
}

//描画の結果を処理
void Game::GenerateOutput()
{
}

//起動時の読込
void Game::LoadData()
{
	DirtTile* dirtTile = new DirtTile(this);
	dirtTile->SetPosition(Vec2(400.0f, 300.0f));

}

//終了時の処理
void Game::UnloadData()
{
}

void Game::Shutdown()
{
}

void Game::AddActor(Actor* actor)
{
	//アクターを更新する際は、ぺディングに追加
	if (mUpdatingActors)
	{
		mPendingActors.emplace_back(actor);
	}
	else
	{
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor)
{
	//待機中のアクターかどうか
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		//配列の一番後ろに移動しポップアップ
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}

	//通常のアクターかどうか
	iter = std::find(mActors.begin(), mActors.end(), actor);
	if(iter != mActors.end())
	{
		//配列の一番後ろに移動しポップアップ
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

void Game::AddSprite(SpriteComponent* sprite)
{
	//ソートされた配列のどこに入れるか検索
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();

	for (; iter != mSprites.end(); ++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}

	//イテレータの位置より前に要素を挿入する
	mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	mSprites.erase(iter);
}




