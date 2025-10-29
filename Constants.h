#pragma once

#include <Siv3D.hpp>

namespace Constants
{
	constexpr StringView TitleName = U"Sin";

	constexpr int ScreenHeight = 900;
	constexpr int ScreenWidth = 1600;

	constexpr Color Gold = Color(Color(U"#ffd700"));

	Array<TextureRegion> LoadTextureRegions(const FilePath& path, const Size& size);
}
