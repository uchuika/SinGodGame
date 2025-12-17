#pragma once

#include "Rule.h"

namespace SinGame
{
	class RWeather : public Rule
	{
	public:
		RWeather(class Game* game);

		void ApplyRule() override;
	private:

	};
}

