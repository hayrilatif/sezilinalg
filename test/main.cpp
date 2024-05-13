#include "sezilinalg.h"
#include <iostream>

using namespace sezilinalg;

int main() {
	objects::Matrix m(10, 1024);
	objects::fillers::constantMatrix(m,2);

	
	objects::Matrix n(1024, 10);
	objects::fillers::constantMatrix(n,2);

	objects::Matrix r = operations::dotProduct(m, n);

	r.printMatrix();


	std::cin.get();

	return 0;
}