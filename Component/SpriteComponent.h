#pragma once

#include <Siv3D.hpp>
#include "Component.h"
#include "../Actor/Actor.h"

namespace SinGame
{
	class SpriteComponent : public Component
	{
	public:
		//(ドロー順位が低いほど公法に位置する)
		SpriteComponent(class Actor* owner, int drawOrder = 100);
		~SpriteComponent();

		virtual void Draw();
		virtual void SetTexture(const Texture texture);

		int GetDrawOrder() const { return mDrawOrder; }
		int GetTexHeight() const { return mTexture.height(); }
		int GetTexWidth() const { return mTexture.width(); }

	protected:
		Texture mTexture;
		int mDrawOrder;

	};

}
