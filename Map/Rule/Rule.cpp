#include "Rule.h"

using namespace SinGame;

Rule::Rule(class Game* game)
	:mGame(game)
{
	mWorld = mGame->GetWorld();
}

Rule::~Rule()
{
}

void Rule::ApplyRule()
{

}
