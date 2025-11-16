#pragma once

namespace SinGame
{
	class GridTexture
	{
	public:
		// 既定のコンストラクタを追加
		GridTexture() = default;
		GridTexture(const Image& image);

		Array<Texture>& GetGridTextures() { return mGridTextures; }
		
	private:
		void MakeTile(const Image& baseImage, const int size);

		void MakeTileByHeightWidth(const Image& baseImage, const int height, const int width);

		Array<Texture> mGridTextures;
	};
}
