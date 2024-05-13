#include "structs.h"

namespace sezilinalg {
	namespace objects {
		bool operator==(Shape& s1, Shape& s2) {
			return (s1.size_c == s2.size_c) && (s1.size_r == s2.size_r);
		}
		bool operator==(Coordinate& s1, Coordinate& s2) {
			return (s1.c == s2.c) && (s1.r == s2.r);
		}

		bool operator!=(Shape& s1, Shape& s2) {
			return !(s1 == s2);
		}
		bool operator!=(Coordinate& s1, Coordinate& s2) {
			return !(s1 == s2);
		}
	}
}