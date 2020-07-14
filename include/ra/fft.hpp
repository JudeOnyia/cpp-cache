#ifndef FFTHPP
#define FFTHPP
#include<cstddef>
#include "ra/matrix_transpose.hpp" // void matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b)
#include<limits>
#include<boost/math/constants/constants.hpp>
#include<cmath> // std::sqrt(#)  and  std::log2(#)  and std::pow(base_size_t, power_size_t)
#include<complex> // std::pow(base_complex, power_complex)

namespace ra::cache {

	template <class K>
	void forward_fft(std::complex<K>* x, std::size_t n){
		using T = std::complex<K>;
		static K K_pi(boost::math::constants::pi<K>());
		static K K_e(boost::math::constants::e<K>());

		static T T_pi(K_pi,0);
		static T T_e(K_e,0);
		static T T_j = T(0,1);

		// base case
		if(n<=4){
			// if n = 0 or 1, do nothing b/c trivial. n cannot be 3 b/c n must be a power of 2
			if(n==2){
				T dft0 = x[0] + x[1];
				T dft1 = x[0] - x[1];
				x[0] = dft0; x[1] = dft1;
			}
			if(n==4){
				T dft0 = x[0] + x[1] + x[2] + x[3];
				T dft1 = x[0] - x[2] + (T_j * (x[3] - x[1]));
				T dft2 = x[0] - x[1] + x[2] - x[3];
				T dft3 = x[0] - x[2] + (T_j * (x[1] - x[3]));
				x[0] = dft0; x[1] = dft1; x[2] = dft2; x[3] = dft3;
			}
		}
		// Recurse case
		else{
			// factor n into n1*n2, where n1 is as close to sqrt(n) as possible
			std::size_t exp_of_n = std::log2(n);
			std::size_t exp_of_n1 = exp_of_n / 2;
			std::size_t exp_of_n2 = exp_of_n - exp_of_n1;
			std::size_t n1 = std::pow(2,exp_of_n1);
			std::size_t n2 = std::pow(2,exp_of_n2);

			matrix_transpose(x, n1, n2, x); // Treat x as a x[n1][n2] matrix and transpose it in-place to x[n2][n1]

			// Replace each row with n1-point DFT recursively
			for(std::size_t i=0; i<n2; ++i){
				T* xi = x + (i*n1);
				forward_fft(xi, n1);
			}

			// Muliply by twiddle factors
			T WN = std::pow(T_e, -(T_j * T(2,0) * T_pi / T(n,0)));
			for(std::size_t i=0; i<n2; ++i){
				for(std::size_t j=0; j<n1; ++j){
					x[i*n1+j] *= std::pow(WN, (i*j));
				}
			}

			matrix_transpose(x, n2, n1, x); // Transpose x[n2][n1] in-place to x[n1][n2]

			// Replace each row with n2-point DFT recursively
			for(std::size_t i=0; i<n1; ++i){
				T* xi = x + (i*n2);
				forward_fft(xi, n2);
			}

			matrix_transpose(x, n1, n2, x); // Transpose x to yield array with elements in correct order
		}
	}


}
#endif
