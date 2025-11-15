#pragma once
#include <Siv3D.hpp>
#include "Actor/Actor.h"
#include "Singleton.h"
#include "Scene/IOnSceneChangedListener.h"

namespace SinGame
{
	enum flowChartState
	{
		TitleChart,
		GameChart,
	};

	class Game : public IOnSceneChangedListener
	{
	public:
		Game();

		bool Inisitalize();
		void RunLoop();
		void Shutdown();

		void AddActor(class Actor* actor);
		void RemoveActor(class Actor* actor);

		void AddSprite(class SpriteComponent* sprite);
		void RemoveSprite(class SpriteComponent* sprite);

		void AddUISprite(class UISpriteComponent* ui);
		void RemoveUISprite(class UISpriteComponent* ui);

		void AddCharacter(class CharacterComponent* chara);
		void RemoveCharacter(class CharacterComponent* chara);

		void SetFlowChartState(flowChartState state) { mFlowChartState = state; }
		flowChartState GetFlowChartState() { mFlowChartState; }

		//テクスチャの登録と取得
		Texture GetTexture(const std::string fileName);

		Array<class SpriteComponent*>& GetSprites() { return mSprites; }
		Array<class UISpriteComponent*>& GetUISprites() { return mUISprites; }
		Array<class CharacterComponent*>& GetCharacters() { return mCharacters; }
		Array<class Actor*>& GetActors() { return mActors; }

		//ゲッター/セッター
		Camera2D GetCamera() { return mCamera; }

		void onSceneChanged(const EScene scene, const Parameter& parameter, const bool stackClear) override;
		void onSceneChanged(const bool popScene) override;

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

		//UIスプライトコンポーネントの配列
		Array<class UISpriteComponent*> mUISprites;

		//描画キャラクターコンポーネントの配列
		Array<class CharacterComponent*> mCharacters;

		//チャートの状態
		flowChartState mFlowChartState;

		class Game* mGame;

		Camera2D mCamera;

		//シーンのスタック
		std::stack<std::shared_ptr<AbstractScene>> mSceneStack;

		//シーンマネージャー
		//SceneManager<String> mSceneManager;
	};

}
