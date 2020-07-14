#include <complex>
#include "ra/fft.hpp"

namespace rc = ra::cache;

template <class T>
void test()
{
	T a[1024];
	rc::forward_fft(&a[0], 16);
}

int main()
{
	test<std::complex<float>>();
	test<std::complex<double>>();
}
