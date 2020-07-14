#include "ra/fft.hpp"
#include<iostream>
#include<cstddef>
#include<complex>

int main(){
	/*
	using K = double;
	using T = std::complex<K>;
	K K_pi(boost::math::constants::pi<K>());
	K K_e(boost::math::constants::e<K>());
	T T_j = T(0,1);
	T T_pi = T(K_pi,0);
	T T_e = T(K_e,0);
	T WN = std::pow(T_e, -(T_j * T(2,0) * T_pi / T(4,0)));
	std::cout<<WN<<std::endl;
	*/

	
	using std::cout;
	using std::endl;
	using type_t = std::complex<double>;

	std::size_t N = 32;
	type_t* x = new type_t[N]; // Create array x

	// Initialize array x
	for(std::size_t i=0; i<N; ++i){
		x[i] = i;
	}

	// Test fft function
	ra::cache::forward_fft(x,N);

	// display result
	for(std::size_t i=0; i<N; ++i){
		cout<<(x[i])<<" ";
	}
	cout<<endl;

	delete[] x; // Free x
	
}
