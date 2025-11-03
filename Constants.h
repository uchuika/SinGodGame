#pragma once

#include <Siv3D.hpp>

namespace Constants
{
	constexpr StringView TitleName = U"Sin";

	constexpr int ScreenHeight = 900;
	constexpr int ScreenWidth = 1600;

	constexpr Color Gold = Color(Color(U"#ffd700"));
	constexpr Color AquaMarine = Color(Color(U"#67b5b7"));

	Array<TextureRegion> LoadTextureRegions(const FilePath& path, const Size& size);
}
