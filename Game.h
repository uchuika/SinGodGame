#pragma once
#include <Siv3D.hpp>
#include "Actor/Actor.h"
#include "Singleton.h"
#include "Scene/CommonSceneData.h"
#include "Scene/IOnSceneChangedListener.h"

namespace SinGame
{
	enum flowChartState
	{
		TitleChart,
		GameChart,
	};

	class Game : public Singleton<class Game>, public IOnSceneChangedListener
	{
	public:
		Game();
		friend Singleton<Game>;

		bool Inisitalize();
		void RunLoop();
		void Shutdown();

		void AddActor(class Actor* actor);
		void RemoveActor(class Actor* actor);

		void AddSprite(class SpriteComponent* sprite);
		void RemoveSprite(class SpriteComponent* sprite);

		void SetFlowChartState(flowChartState state) { mFlowChartState = state; }
		flowChartState GetFlowChartState() { mFlowChartState; }

		//テクスチャの登録と取得
		Texture GetTexture(const std::string fileName);

		Array<class SpriteComponent*>& GetSprites() { return mSprites; }

		//ゲッター/セッター
		Camera2D GetCamera() { return mCamera; }

	private:
		void ProcessInput();
		void UpdateGame();
		void GenerateOutput();
		void LoadData();
		void UnloadData();
		void DoChart();

		//現在アクターを更新しているかどうか
		bool mUpdatingActors;

		//テクスチャを保存するマップ
		std::unordered_map<std::string, Texture> mTextures;

		//全てのアクターを格納
		Array<class Actor*> mActors;

		//待機中のアクターを格納
		Array<class Actor*> mPendingActors;

		//描画スプライトコンポーネントの配列
		Array<class SpriteComponent*> mSprites;

		//チャートの状態
		flowChartState mFlowChartState;

		class Game* mGame;

		Camera2D mCamera;

		//シーンマネージャー
		SceneManager<String> mSceneManager;
	};

}
