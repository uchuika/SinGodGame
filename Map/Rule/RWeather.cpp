#include "RWeather.h"
#include "../../Game.h"

using namespace SinGame;

RWeather::RWeather(class Game* game)
	:Rule(game)
{

}

void RWeather::ApplyRule()
{
	Logger << U"RWeather Apply";
}
