#include <complex>
#include "ra/matrix_multiply.hpp"

namespace rc = ra::cache;

template <class T>
void test()
{
	constexpr T a[1024] = {0};
	T b[1024];
	T c[1024];
	rc::matrix_multiply(&a[0], &b[0], 2, 2, 2, &c[0]);
	rc::naive_matrix_multiply(&a[0], &b[0], 2, 2, 2, &c[0]);
}

int main()
{
	test<int>();
	test<double>();
	test<std::complex<double>>();
}
