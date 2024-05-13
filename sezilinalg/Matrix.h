#pragma once
#include "structs.h"

namespace sezilinalg {
	namespace objects {
		class Matrix {
		public:
			float* d;
			Shape shape;

			int getSize();

			void setElement(int r, int c, int v);
			void setElement(Coordinate coord, int v);

			float getElement(int r, int c);
			float getElement(Coordinate coord);

			void transpose();

			void printMatrix();

			Matrix(int r, int c);
			Matrix(Shape shape);

			static Coordinate getCoordinateFromAbsolute(Shape shape, int t);
			static int getAbsoluteFromCoordinate(Shape shape, Coordinate t);
		};
	}
}
