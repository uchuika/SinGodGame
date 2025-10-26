#pragma once
#include "Actor/Actor.h"

namespace SinGame
{
	class Game
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

	private:
		void ProcessInput();
		void UpdateGame();
		void GenerateOutput();
		void LoadData();
		void UnloadData();

		//現在アクターを更新しているかどうか
		bool mUpdatingActors;

		//全てのアクターを格納
		Array<class Actor*> mActors;

		//待機中のアクターを格納
		Array<class Actor*> mPendingActors;

		//描画スプライトコンポーネントの配列
		Array<class SpriteComponent*> mSprites;
	};

}
