#pragma once
#include "../Game.h"
#include "AbstractScene.h"

namespace SinGame {
	class TitleScene : public AbstractScene
	{
	public:
		TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter, class Game* game);
		virtual ~TitleScene() = default;
		void update() override;
		void draw() const override;
		void drawUI() const override;
		EScene GetScene() const override;
	private:
		class Game* mGame;
	};
}
