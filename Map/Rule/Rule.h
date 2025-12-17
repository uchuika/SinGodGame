#pragma once

#include "../../Game.h"

namespace SinGame
{
	class Rule {
	public:
		Rule(class Game* game);
		virtual ~Rule();

		virtual void ApplyRule();
	private:
		class Game* mGame;
		class World* mWorld;
	};
}
