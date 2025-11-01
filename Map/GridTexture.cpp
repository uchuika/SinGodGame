#include "GridTexture.h"

using namespace SinGame;

GridTexture::GridTexture(const Image& image)
{
	if (image.height() / 12 == image.width() / 16)
	{
		int tileSize = 32;
		MakeTile(image, tileSize);
	}
}

void GridTexture::MakeTile(const Image& baseImage, const int size)
{
	const int32 halfTileSize = size / 2;
	Array<Texture> textures;

	// 16x12 のグリッドからタイル画像を切り出す
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 12; j++) {
			// タイルの左上座標
			int x = size * i;
			int y = size * j;

			// baseImage から size x size の領域を切り出す
			Image tileImage = baseImage.clipped(x, y, size, size);

			// Texture に変換して配列に追加
			textures.push_back(Texture(tileImage));
			tileImage.release();
		}
	}

	mGridTextures = textures;
}
