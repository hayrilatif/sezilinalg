#pragma once
#include "Matrix.h"

namespace sezilinalg {
	namespace objects {
		namespace fillers {
			void constantMatrix(Matrix& x, float v);
			void identityMatrix(Matrix& x);
			void randomNormalMatrix(Matrix& x, float mean, float std, unsigned int seed = 42);
		}
	}
}