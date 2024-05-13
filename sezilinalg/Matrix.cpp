#include "structs.h"
#include "Matrix.h"
#include <iostream>

namespace sezilinalg {
	namespace objects {
		int Matrix::getSize() {
			return shape.size_r * shape.size_c;
		}

		void Matrix::setElement(int r, int c, int v) {
			Coordinate coord;
			coord.c = c;
			coord.r = r;
			int absolute = Matrix::getAbsoluteFromCoordinate(shape, coord);
			d[absolute] = v;
		}
		void Matrix::setElement(Coordinate coord, int v) {
			int absolute = Matrix::getAbsoluteFromCoordinate(shape, coord);
			d[absolute] = v;
		}

		float Matrix::getElement(int r, int c) {
			Coordinate coord;
			coord.c = c;
			coord.r = r;
			int absolute = Matrix::getAbsoluteFromCoordinate(shape, coord);
			return d[absolute];
		}
		float Matrix::getElement(Coordinate coord) {
			int absolute = Matrix::getAbsoluteFromCoordinate(shape, coord);
			return d[absolute];
		}

		void Matrix::transpose() {
			Shape new_shape;
			new_shape.size_c = shape.size_r;
			new_shape.size_r = shape.size_c;
			shape = new_shape;
		}

		void Matrix::printMatrix() {
			std::cout << std::endl << "Matrix" << std::endl;
			
			int r = 0, c = 0;

			for (int i = 0; i < shape.size_r; i++)
			{
				for (int j = 0; j < shape.size_c; j++)
				{
					Coordinate coord;
					coord.r = i;
					coord.c = j;

					int absolute = getAbsoluteFromCoordinate(shape, coord);
					std::cout << d[absolute] << " ";
				}
				std::cout << std::endl;
			}
		}

		Matrix::Matrix(int r, int c) {
			d = new float[r * c];
			shape.size_r = r;
			shape.size_c = c;
		}

		Matrix::Matrix(Shape shape) {
			d = new float[shape.size_r * shape.size_c];
			this->shape.size_r = shape.size_r;
			this->shape.size_c = shape.size_c;
		}

		Coordinate Matrix::getCoordinateFromAbsolute(Shape shape, int t) {
			Coordinate res;
			res.c = t % shape.size_c;
			res.r = (int)(t / shape.size_r);
			return res;
		}
		int Matrix::getAbsoluteFromCoordinate(Shape shape, Coordinate t) {
			return (t.r * shape.size_c) + t.c;
		}
	}
}