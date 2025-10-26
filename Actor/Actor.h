#pragma once
#include "../Game.h"

namespace SinGame
{
	class Actor
	{
	public:
		enum State
		{
			EActive,
			EPaused,
			EDead
		};

		Actor(class Game* game);
		virtual ~Actor();

		//ゲームから呼び出される更新関数(オーバーライド不可)
		void Update(double deltaTime);

		//アクターにアタッチされた全てのコンポーネントを更新
		void UpdateComponents(double deltaTime);

		//アクター固有の更新コード(オーバーライド可能)
		virtual void UpdateActor(double deltaTime);

		//ゲッター/セッター
		const Vec2 GetPosition() const { return mPosition; }
		void SetPosition(const Vec2 pos) { mPosition = pos; }

		float GetScale() const { return mScale; }
		void SetScale(float scale) { mScale = scale; }

		float GetRotation() const { return mRotation; }
		void SetRotation(float rotation) { mRotation = rotation; }

		State GetState() const { return mState; }
		void SetState(State state) { mState = state; }

		class Game* GetGame() { return mGame; }

		//コンポーネントの追加と削除
		void AddComponent(class Component* component);
		void RemoveComponent(class Component* component);

	private:
		//アクターの状態
		State mState;

		//各種パラメータ
		Vec2 mPosition;
		float mScale;
		float mRotation;

		//アクターが持っているコンポーネントの配列
		Array<class Component*> mComponents;
		class Game* mGame;
	};
}

