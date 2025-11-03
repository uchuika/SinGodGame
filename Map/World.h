#pragma once

#include "../Game.h"

namespace SinGame
{
	enum WeatherState
	{
		Sunny,
		Rain,
		Cloudy
	};
	enum SeasonState
	{
		Spring,
		Summer,
		Autumn,
		Winter,
	};

	class World : public Actor
	{
	public:
		World(class Game* game);

		
		WeatherState GetWeatherState() { return mWeatherState; }
		void SetWeatherState(WeatherState state) { mWeatherState = state; }
		
		SeasonState GetSeasonState() { return mSeasonState; }
		void SetSeasonState(SeasonState state) { mSeasonState = state;  }

		int GetTempLevel() { return mTempLevel; }
		void SetTempLevel(int tempLevel) { mTempLevel = tempLevel; }

		void Update();

	private:
		WeatherState mWeatherState;
		int mTempLevel;
		SeasonState mSeasonState;
	};
}
