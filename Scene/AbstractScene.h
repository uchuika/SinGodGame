#pragma once

#include "../Game.h"
#include "IOnSceneChangedListener.h"
#include "Parameter.h"
#include "Math.h"

namespace SinGame {
	class IOnSceneChangedListener;

	//ストラテジーパターンという物を使ってシーンスタック側は指示された
// インスタンスを条件分岐させながら作るだけで完了となるよう設計
	class AbstractScene
	{
	protected:
		IOnSceneChangedListener* _implSceneChanged;

	public:
		AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game);
		virtual ~AbstractScene() = default;
		virtual void update() = 0;
		virtual void draw() const = 0;
		virtual void drawUI() = 0;
		virtual EScene GetScene() const = 0;
	};

}
