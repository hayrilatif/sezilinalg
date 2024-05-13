#include "Operations.h"
#include "Matrix.h"
#include <iostream>

namespace sezilinalg {
	namespace operations {
		sezilinalg::objects::Matrix getRow(sezilinalg::objects::Matrix& x,int r) {
			if (r>=x.shape.size_r)
			{
				std::cout << "getRow: The row is not exist!";
				sezilinalg::objects::Matrix res(1, 1);
				sezilinalg::objects::fillers::constantMatrix(res, -1);
				return res;
			}

			sezilinalg::objects::Matrix res(1, x.shape.size_c);

			float* x_ptr = x.d;
			float* res_ptr = res.d;

			x_ptr += r * x.shape.size_c;

			for (int i = 0; i < x.shape.size_c; i++)
			{
				(*res_ptr++) = *x_ptr++;
			}
			
			return res;
		}
		sezilinalg::objects::Matrix getColumn(sezilinalg::objects::Matrix& x, int c) {
			x.transpose();
			sezilinalg::objects::Matrix res = getRow(x, c);
			res.transpose();
			x.transpose();
			return res;
		}


		
		float sum(sezilinalg::objects::Matrix m) {
			float* m_ptr = m.d;
			float sum = 0;
			for (int i = 0; i < m.getSize(); i++)
			{
				sum += *m_ptr++;
			}
			return sum;
		}
		float prod(sezilinalg::objects::Matrix m) {
			float* m_ptr = m.d;
			float sum = 0;
			for (int i = 0; i < m.getSize(); i++)
			{
				sum *= *m_ptr++;
			}
			return sum;
		}
		float mean(sezilinalg::objects::Matrix m) {
			float* m_ptr = m.d;
			float sum = 0;
			int m_size = m.getSize();
			for (int i = 0; i < m_size; i++)
			{
				sum += *m_ptr++;
			}
			return sum / (float)(m_size);
		}

		sezilinalg::objects::Matrix elementwiseAddition(sezilinalg::objects::Matrix& x, sezilinalg::objects::Matrix& y) {
			if (x.shape != y.shape)
			{
				std::cout << "elementwiseAddition: Shape mismatch!";
				sezilinalg::objects::Matrix res(1, 1);
				sezilinalg::objects::fillers::constantMatrix(res, -1);
				return res;
			}

			sezilinalg::objects::Matrix res(x.shape);

			float* res_d_ptr = res.d;
			float* x_d_ptr = x.d;
			float* y_d_ptr = y.d;

			for (int i = 0; i < x.getSize(); i++)
			{
				*res_d_ptr++ = (*x_d_ptr++) + (*y_d_ptr++);
			}
			return res;
		}
		sezilinalg::objects::Matrix elementwiseAddition(sezilinalg::objects::Matrix& x, float y) {
			sezilinalg::objects::Matrix res(x.shape);

			float* res_d_ptr = res.d;
			float* x_d_ptr = x.d;
			
			for (int i = 0; i < x.getSize(); i++)
			{
				*res_d_ptr++ = (*x_d_ptr++) + y;
			}
			return res;
		}


		sezilinalg::objects::Matrix elementwiseMultiplication(sezilinalg::objects::Matrix& x, sezilinalg::objects::Matrix& y) {
			if (x.shape!=y.shape)
			{
				std::cout << "elementwiseMultiplication: Shape mismatch!";
				sezilinalg::objects::Matrix res(1, 1);
				sezilinalg::objects::fillers::constantMatrix(res, -1);
				return res;
			}
			
			sezilinalg::objects::Matrix res(x.shape);

			float* res_d_ptr = res.d;
			float* x_d_ptr = x.d;
			float* y_d_ptr = y.d;

			for (int i = 0; i < x.getSize(); i++)
			{
				*res_d_ptr++ = (*x_d_ptr++) * (*y_d_ptr++);
			}
			return res;
		}
		sezilinalg::objects::Matrix elementwiseMultiplication(sezilinalg::objects::Matrix& x, float y) {
			sezilinalg::objects::Matrix res(x.shape);

			float* res_d_ptr = res.d;
			float* x_d_ptr = x.d;

			for (int i = 0; i < x.getSize(); i++)
			{
				*res_d_ptr++ = (*x_d_ptr++) * y;
			}
			return res;
		}

		sezilinalg::objects::Matrix oneOver(sezilinalg::objects::Matrix& m) {
			sezilinalg::objects::Matrix res(m.shape);
			float* m_ptr = m.d;
			float* res_ptr = res.d;

			for (int i = 0; i < m.getSize(); i++)
			{
				*res_ptr++ = 1 / (*m_ptr++);
			}
			return res;
		}

		sezilinalg::objects::Matrix dotProduct(sezilinalg::objects::Matrix& x, sezilinalg::objects::Matrix& y) {
			sezilinalg::objects::Shape res_shape;
			res_shape.size_r = x.shape.size_r;
			res_shape.size_c = y.shape.size_c;
			

			sezilinalg::objects::Matrix res(res_shape);

			for (int i = 0; i < res_shape.size_r; i++)
			{
				sezilinalg::objects::Matrix row = sezilinalg::operations::getRow(x, i);
				row.transpose();

				for (int j = 0; j < res_shape.size_c; j++)
				{
					sezilinalg::objects::Matrix col = sezilinalg::operations::getColumn(y, j);

					sezilinalg::objects::Matrix mul = elementwiseMultiplication(row, col);
					float v = sum(mul);

					res.setElement(i, j, v);
				}
			}
			return res;
		}
	}
}