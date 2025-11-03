#include "GridTexture.h"

using namespace SinGame;

GridTexture::GridTexture(const Image& image)
{
	if (image.height() / 4 == 28)
	{
		int tileHeight = 28;
		int tileWidth = 20;
		MakeTileByHeightWidth(image, tileHeight, tileWidth);
	}
	else if (image.height() / 12 == image.width() / 16)
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

void GridTexture::MakeTileByHeightWidth(const Image& baseImage, const int height, const int width)
{
	Array<Texture> textures;

	for (int i = 0; i < baseImage.width()/width; i++)
	{
		for (int j = 0; j < baseImage.height() / height; j++)
		{
			//タイルの左上座標
			int x = width * i;
			int y = height * j;

			//baseImageからwidth x heightの領域を切り出す
			Image tileImage = baseImage.clipped(x, y, width, height);

			textures.push_back(Texture(tileImage));
			tileImage.release();
		}

		mGridTextures = textures;
	}
}


