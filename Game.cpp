// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include <Siv3D.hpp>
#include "Game.h"
#include "Actor/Actor.h"
#include "Actor/DirtTile.h"
#include "Component/SpriteComponent.h"
#include "Scene/GameScene.h"
#include "Scene/TitleScene.h"
#include "Scene/CommonSceneData.h"

using namespace SinGame;

Game::Game()
	:mUpdatingActors(false)
	,mGame(this)
{
}



bool Game::Inisitalize()
{
	mCamera = Camera2D(Vec2{ 960, 540 }, 1.0);

	//シーンマネージャーの宣言
	//SceneManager<String> sceneManager;

	LoadData();

#if _DEBUG
	/*
	//デバッグ時は直接ゲームシーンへ
	mSceneManager.add<GameScene>(U"GameScene");
	mSceneManager.init(U"GameScene", 0.0s);
	mFlowChartState = GameChart;
	*/
	//タイトル画面シーンを作ってpush
	Parameter parameter;
	mSceneStack.push(std::make_shared<GameScene>(this, parameter, this));


#else
	//sceneManager.add<TitleScene>(U"TitleScene");
	Parameter parameter;
	mSceneStack.push(std::make_shared<TitleScene>(this, parameter, this));
#endif


	return true;
}

//タスクを順番に実行
void Game::RunLoop()
{
	ProcessInput();
	UpdateGame();
	GenerateOutput();
}

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

	//スタックのトップのシーンを更新
	mSceneStack.top()->update();

	//カメラの更新
	mCamera.update();

	//フローチャートの実行
	DoChart();

	/*
	mSceneManager.update();
	*/
}

//ゲームループのフローチャート
void Game::DoChart()
{
	/*
	switch (mFlowChartState)
	{
		case TitleChart:
			//タイトル画面の処理
			break;

		case GameChart:

	}
	*/
}


//描画の結果を処理
void Game::GenerateOutput()
{
	mSceneStack.top()->draw();

	mSceneStack.top()->drawUI();
}

//起動時の読込
void Game::LoadData()
{
	
}

//終了時の処理
void Game::UnloadData()
{
}

void Game::Shutdown()
{
}

//テクスチャの登録と取得
Texture Game::GetTexture(const std::string fileName)
{
	Texture tex;
	// Is the texture already in the map?
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end())
	{
		tex = iter->second;
	}
	else
	{

		// Create texture from surface
		tex = Texture{ Unicode::Widen(fileName) };
		

		mTextures.emplace(fileName, tex);
	}
	return tex;
}

void Game::AddActor(Actor* actor)
{
	//アクターを更新する際は、ぺンディングに追加
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
	// ソートされたベクトルの挿入点を見つける
	// (自分よりドロー順位の高い最初の要素)
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (;
		iter != mSprites.end();
		++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}

	// イテレータの位置より前に要素を挿入する
	mSprites.insert(iter, sprite);
	//Logger << mSprites.size();
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	mSprites.erase(iter);
}

void Game::onSceneChanged(const EScene scene, const Parameter& parameter, const bool stackClear)
{
	if (stackClear) {	//スタッククリア
		//スタックを全部ポップする(スタックを空にする)
		while (!mSceneStack.empty()) {
			mSceneStack.pop();
		}
	}

	switch (scene) {
	case EScene::Title:
		mSceneStack.push(std::make_shared<TitleScene>(this, parameter, this));
		break;
	case EScene::Game:
		mSceneStack.push(std::make_shared<GameScene>(this, parameter, this));
		break;
	default:
		//存在しないシーンが呼ばれたどうしようもないエラーが発生
		break;
	}
}

void Game::onSceneChanged(const bool popScene)
{
	if (popScene) {
		mSceneStack.pop();
	}
}








