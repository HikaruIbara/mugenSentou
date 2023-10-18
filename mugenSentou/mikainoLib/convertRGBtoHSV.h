#pragma once

namespace MSL
{
	struct rgb final
	{
		int r{};
		int g{};
		int b{};
		int a{};

	};	struct hsv final
	{
		int h{};
		int s{};
		int v{};
		int a{};

	};


	/// <summary>
	/// h=0~255 s=0~255 v=0~255
	/// </summary>
	/// <param name="hsv"></param>
	/// <returns></returns>
	rgb GetColorHSVToRGB(hsv hsv);
}
