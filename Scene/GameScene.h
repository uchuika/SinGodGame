#pragma once
#include "../Game.h"

namespace SinGame
{
	class GameScene : public SceneManager<String>::Scene
	{
	public:
		GameScene(const InitData& init);
		void update() override;
		//void draw() const override;
	};

}
