// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Component.h"
#include "../Game.h"
#include "../Actor/Actor.h"

using namespace SinGame;

Component::Component(class Actor* owner, int updateOrder)
	:mOwner(owner)
	, mUpdateOrder(updateOrder)
{
	//インスタンスが作られたときActorの配列に追加
	mOwner->AddComponent(this);
}

Component::~Component()
{
	//インスタンスが破棄されるときActorの配列から削除
	mOwner->RemoveComponent(this);
}

void Component::Update(double deltaTime)
{
	//デフォルトでは何もしない
}


