#pragma once
#include "DirtTile.h"
#include "../Actor/Actor.h"

namespace SinGame
{
	class DirtTile : public Actor
	{
	public:
		DirtTile(class Game* game);

		void UpdateActor(double deltaTIme) override;

	private:
		
	};

}
