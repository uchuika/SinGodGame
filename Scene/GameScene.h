#pragma once

#include <Siv3D.hpp>
#include "../Game.h"
#include "../Actor/Actor.h" // 追加: Actorクラスの定義をインクルード

namespace SinGame
{
	class GameScene : public SceneManager<String>::Scene
	{
	public:
		GameScene(const InitData& init);

		void update() override;
		//void draw() const override;

		void drawUI() const;

	private:
		Grid<Actor*> mTileGrid;

		
	};

}
