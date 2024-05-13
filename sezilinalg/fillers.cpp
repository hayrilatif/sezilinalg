#include "fillers.h"
#include <vcruntime_string.h>

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
		}
	}
}