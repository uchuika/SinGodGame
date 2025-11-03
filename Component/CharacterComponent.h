#pragma once

#include <Siv3D.hpp>
#include "Component.h"
#include "../Actor/Actor.h"

namespace SinGame
{
	class CharacterComponent : public Component
	{
	public:
		//ドロー順位が低いほど後方に位置する
		CharacterComponent(class Actor* owner, int drawOrder = 100);
		~CharacterComponent();

		virtual void Draw();
		virtual void SetCharaTexture(const Texture texture);
		virtual void SetTexState(int texState);

		int GetDrawOrder() const { return mDrawOrder; }
		int GetTexHeight() const { return mCharaTexture.height(); }
		int GetTexWidth() const { return mCharaTexture.width(); }

	protected:
		Texture mCharaTexture;
		int mDrawOrder;
		int animationIndex;
		int direction;
	};
}
