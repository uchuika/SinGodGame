#include "Constants.h"

using namespace Constants;

Array<TextureRegion> Constants::LoadTextureRegions(const FilePath& path, const Size& size)
{
	const Texture texture(path);

	Array<TextureRegion> textureRegions;

	for (auto p : step(Size(texture.width() / size.x, texture.height() / size.y)))
	{
		textureRegions.push_back(texture(p * size, size));
	}

	return textureRegions;
}
