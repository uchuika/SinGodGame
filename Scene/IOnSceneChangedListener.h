#pragma once

#include "EScene.h"
#include "AbstractScene.h"
#include "Parameter.h"


namespace SinGame
{
	class IOnSceneChangedListener
	{
	public:
		IOnSceneChangedListener() = default;
		virtual ~IOnSceneChangedListener() = default;
		virtual void onSceneChanged(const EScene scene, const Parameter& parameter, const bool stackClear) = 0;
		virtual void onSceneChanged(const bool popScene) = 0;
	};

}

