#include "Actor.h"
#include "../Game.h"
#include "../Component/Component.h"

using namespace SinGame;

Actor::Actor(class Game* game)
	: mState(EActive)
	, mPosition(Vec2::Zero())
	, mScale(1.0f)
	, mRotation(0.0f)
	, mGame(game)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
}

void Actor::Update(double deltaTime)
{
	//アクターが現在有効な状態なら
	if (mState == EActive)
	{
		//コンポーネントとアクターを更新
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(double deltaTime)
{
	//コンポーネント配列に格納された各種コンポーネントをデルタタイムで更新
	for (auto component : mComponents)
	{
		component->Update(deltaTime);
	}
}

void Actor::UpdateActor(double deltaTime)
{

}

void Actor::AddComponent(class Component* component)
{
	//ソートされた配列のどこに入れ込むかを調べる
	//自分自身より順位が高い最初の要素
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();

	for(; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	//イテレータの位置より前に要素を挿入する
	mComponents.insert(iter, component);

}

void Actor::RemoveComponent(class Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}

}

