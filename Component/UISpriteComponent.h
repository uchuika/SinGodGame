#pragma once

#include <Siv3D.hpp>
#include "Component.h"
#include "../Actor/Actor.h"

namespace SinGame
{
	class UISpriteComponent : public Component
	{
	public:
		//(ドロー順位が低いほど公法に位置する)
		UISpriteComponent(class Actor* owner, int drawOrder = 100);
		~UISpriteComponent();

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
