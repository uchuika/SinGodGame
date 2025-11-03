#include "World.h"

using namespace SinGame;

World::World(class Game* game)
{
	mWeatherState = WeatherState(Random(0, 2));
	mTempLevel = Random(0, 40);
	mSeasonState = SeasonState(Random(0,3));
}

void World::Update()
{
	//確立によって各種パラメータを変更
	//温度の更新
	if (Random(1,4) % 4 == 0)
	{
		mTempLevel += Random(-4,4);
	}
	//季節の更新
	if (Random(1, 100) % 100 == 0)
	{
		//int 
	}
	//天気の変更
	if (Random(1, 20) % 20 == 0)
	{

	}
}
