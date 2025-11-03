#include "World.h"

using namespace SinGame;

World::World(class Game* game)
	:Actor(game)
{
	mWeatherState = WeatherState(Random(0, 2));
	mTempLevel = Random(20, 25);
	mSeasonState = SeasonState(Random(0,3));
	Logger << U"InitWeather {}"_fmt(static_cast<int>(mWeatherState));
	Logger << U"InitTempLevel {}"_fmt(mTempLevel);
	Logger << U"InitSeasonState {}"_fmt(static_cast<int>(mSeasonState));
}

void World::Update()
{
	//確立によって各種パラメータを変更
	//温度の更新
	if (Random(1,4) % 4 == 0)
	{
		mTempLevel += Random(-4,4);
		mTempLevel = Clamp(mTempLevel, 0, 40);
		Logger << U"UpdateTemp {}"_fmt(mTempLevel);
	}
	//季節の更新
	if (Random(1, 100) % 100 == 0)
	{
		mSeasonState = SeasonState((mSeasonState + 1) % 4);
		Logger << U"UpdateSeason";
	}
	//天気の変更
	if (Random(1, 20) % 20 == 0)
	{
		mWeatherState = WeatherState(Random(0, 2));
		Logger << U"UpdateWeather";
			
	}
}
