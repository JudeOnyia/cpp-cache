#include <complex>
#include "ra/matrix_transpose.hpp"

namespace rc = ra::cache;

template <class T>
void test()
{
	constexpr int n = 2;
	constexpr int m = 2;
	constexpr T a[m * n] = {0};
	T b[n * m];
	rc::matrix_transpose(&a[0], m, n, &b[0]);
	rc::naive_matrix_transpose(&a[0], m, n, &b[0]);
}

int main()
{
	test<int>();
	test<double>();
	test<std::complex<double>>();
}
