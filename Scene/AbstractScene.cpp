#pragma once

#include "../Game.h"
#include "AbstractScene.h"

using namespace SinGame;

AbstractScene::AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game) :
	_implSceneChanged(impl)
{
}
