#pragma once
#include <Siv3D.hpp>
#include "Component.h"

namespace SinGame
{
	class CircleComponent : public Component
	{
	public:
		CircleComponent(class Actor* owner);

		void SetRadius(float radius) { mRadius = radius; }
		float GetRadius() const;

		const Vec2& GetCenter() const;
	private:
		float mRadius;
	};

	bool Intersect(const CircleComponent& a, const CircleComponent& b);

}
