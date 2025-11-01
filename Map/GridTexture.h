#pragma once

namespace SinGame
{
	class GridTexture
	{
	public:
		GridTexture(const Image& image);

		Array<Texture>& GetGridTextures() { return mGridTextures; }

	private:
		void MakeTile(const Image& baseImage, const int size);

		Array<Texture> mGridTextures;
	};
}
