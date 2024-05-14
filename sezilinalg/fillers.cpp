#include "fillers.h"
#include <random>
#include <stdlib.h>

namespace sezilinalg {
	namespace objects {
		namespace fillers{
			void constantMatrix(Matrix&x,float v) {
				int size = x.getSize();

				float* _d = x.d;

				for (int i = 0; i < size; i++)
				{
					*_d++ = v;
				}
			}

			void identityMatrix(Matrix& x) {
				if (x.shape.size_c!=x.shape.size_r)
				{
					return;
				}
				
				constantMatrix(x, 0);

				for (int i = 0; i < x.shape.size_c; i++)
				{
					x.setElement(i, i, 1);
				}
			}

			void randomNormalMatrix(Matrix& x, float mean, float std, unsigned int seed) {
				int size = x.getSize();

				float* _d = x.d;

				auto dist = std::normal_distribution<float>{ mean, std };
				auto urbg = std::mt19937{ seed };

				for (int i = 0; i < size; i++)
				{
					*_d++ = dist(urbg);
				}
			}
		}
	}
}