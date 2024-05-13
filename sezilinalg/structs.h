#pragma once

namespace sezilinalg {
	namespace objects {
		struct Shape
		{
			int size_r, size_c;
		};
		struct Coordinate
		{
			int r, c;
		};

		bool operator==(Shape& s1, Shape& s2);
		bool operator==(Coordinate& s1, Coordinate& s2);

		bool operator!=(Shape& s1, Shape& s2);
		bool operator!=(Coordinate& s1, Coordinate& s2);

	}
}