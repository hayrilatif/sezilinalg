#pragma once
#include "Matrix.h"
#include "fillers.h"

namespace sezilinalg {
	namespace operations {
		sezilinalg::objects::Matrix getRow(sezilinalg::objects::Matrix& x, int r);
		sezilinalg::objects::Matrix getColumn(sezilinalg::objects::Matrix& x, int c);

		float sum(sezilinalg::objects::Matrix m);
		float prod(sezilinalg::objects::Matrix m);
		float mean(sezilinalg::objects::Matrix m);
		
		sezilinalg::objects::Matrix elementwiseAddition(sezilinalg::objects::Matrix& x, sezilinalg::objects::Matrix& y);
		sezilinalg::objects::Matrix elementwiseAddition(sezilinalg::objects::Matrix& x, float y);

		sezilinalg::objects::Matrix elementwiseMultiplication(sezilinalg::objects::Matrix& x, sezilinalg::objects::Matrix& y);
		sezilinalg::objects::Matrix elementwiseMultiplication(sezilinalg::objects::Matrix& x, float y);

		sezilinalg::objects::Matrix oneOver(sezilinalg::objects::Matrix& x);

		sezilinalg::objects::Matrix dotProduct(sezilinalg::objects::Matrix& x, sezilinalg::objects::Matrix& y);
	}
}