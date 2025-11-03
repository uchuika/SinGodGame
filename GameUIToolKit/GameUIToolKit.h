#pragma once

#include <Siv3D.hpp>

namespace GameUIToolKit
{
	class ProgressBar
	{
	private:

		RectF m_rect = Rect(0);

		ColorF m_backgroundColor = ColorF(0.25);

		Array<std::pair<double, ColorF>> m_barColors = {
			{ 1.0, ColorF(0.1, 0.8, 0.2) }
		};

		double m_round = 0.0;

		ColorF getBarColor(double progress) const
		{
			ColorF result = m_barColors.front().second;

			for (auto& c : m_barColors)
			{
				if (progress < c.first)
				{
					result = c.second;
				}
				else
				{
					break;
				}
			}

			return result;
		}

	public:

		ProgressBar() = default;

		explicit ProgressBar(const RectF& rect, double round = 0.0)
			: ProgressBar(rect, ColorF(0.25), { { 1.0, ColorF(0.1, 0.8, 0.2) } }, round) {
		}

		ProgressBar(const RectF& rect, const ColorF& backgroundColor, const ColorF& barColor, double round = 0.0)
			: ProgressBar(rect, backgroundColor, { { 1.0, barColor } }, round) {
		}

		ProgressBar(const RectF& rect, const ColorF& backgroundColor, const Array<std::pair<double, ColorF>>& barColors, double round = 0.0)
			: m_rect(rect)
			, m_backgroundColor(backgroundColor)
			, m_barColors(barColors)
			, m_round(round)
		{
			m_barColors.sort_by([](const auto& a, const auto& b) { return a.first > b.first; });
		}

		// バーを描く
		const ProgressBar& draw(double value, double maxValue) const
		{
			const double progress = maxValue ? Math::Saturate(value / maxValue) : 1.0;
			const RectF innnerRect = m_rect.stretched(-1);
			const RectF innnerRectBar(innnerRect.pos, innnerRect.w * progress, innnerRect.h);

			if (m_round == 0.0)
			{
				m_rect.draw(m_backgroundColor);
				innnerRectBar.draw(getBarColor(progress));
			}
			else
			{
				m_rect.rounded(m_round).draw(m_backgroundColor);

				if (innnerRectBar.w)
				{
					const Polygon bar = innnerRectBar.asPolygon();
					const RoundRect innnerRoundRect = innnerRect.rounded(m_round - 1);
					const Polygon clip = innnerRoundRect.asPolygon();

					if (const auto g = Geometry2D::And(bar, clip))
					{
						g.front().draw(getBarColor(progress));
					}
				}
			}

			return *this;
		}

		/*
		// 中央揃えでテキストを描く
		const ProgressBar& withText(const SDFDrawableText& drawableText, double fontSize, const ColorF& textColor, const Vec2& textPosOffset = Vec2(0, 0)) const
		{
			const Size textSize = drawableText.region(fontSize).size;
			const auto& font = drawableText.font;
			const Point textPos = (m_rect.pos + (m_rect.size - textSize) / 2 + textPosOffset).asPoint();
			Graphics2D::SetSDFParameters(font.pixelRange(), 0.2);
			drawableText.draw(fontSize, textPos, ColorF(0.1));
			Graphics2D::SetSDFParameters(font.pixelRange(), 0.0);
			drawableText.draw(fontSize, textPos, textColor);
			return *this;
		}

		// 左揃えでテキストを描く
		const ProgressBar& withLabel(const SDFDrawableText& drawableText, double fontSize, const ColorF& textColor, double offsetX, const Vec2& textPosOffset = Vec2(0, 0)) const
		{
			const Size textSize = drawableText.region(fontSize).size;
			const auto& font = drawableText.font;
			const Point textPos = (Vec2(m_rect.x + offsetX, m_rect.y + (m_rect.h - textSize.y) / 2) + textPosOffset).asPoint();
			Graphics2D::SetSDFParameters(font.pixelRange(), 0.2);
			drawableText.draw(fontSize, textPos, ColorF(0.1));
			Graphics2D::SetSDFParameters(font.pixelRange(), 0.0);
			drawableText.draw(fontSize, textPos, textColor);
			return *this;
		}
		*/
	};
}
