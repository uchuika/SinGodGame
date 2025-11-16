#include "CircleComponent.h"
#include "../Actor/Actor.h"

using namespace SinGame;

CircleComponent::CircleComponent(class Actor* owner)
	:Component(owner)
	, mRadius(0.0f)
{

}

const Vec2& CircleComponent::GetCenter() const
{
	return mOwner->GetPosition();
}

float CircleComponent::GetRadius() const
{
	return mOwner->GetScale() * mRadius;
}

bool SinGame::Intersect(const CircleComponent& a, const CircleComponent& b)
{
	// Calculate distance squared
	Vec2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.lengthSq();

	// Calculate sum of radii squared
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}
