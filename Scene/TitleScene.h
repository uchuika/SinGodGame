#pragma once
#include "../Game.h"

namespace SinGame {
	class TitleScene : public SceneManager<String>::Scene
	{
	public:
		TitleScene(const InitData& init);

		void update() override;

		//void draw() const override;

	};
}
