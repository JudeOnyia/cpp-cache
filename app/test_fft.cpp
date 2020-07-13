#include "ra/fft.hpp"
#include<iostream>
#include<cstddef>
#include<complex>

int main(){
	using std::cout;
	using std::endl;
	using type_t = std::complex<double>;

	N = 4;
	type_t* x = new type_t[N]; // Create array x

	// Initialize array x
	for(std::size_t i=0; i<N; ++i){
		x[i] = i;
	}

	// Test fft function
	forward_fft(x,N);

	// display result
	for(std::size_t i=0; i<N; ++i){
		cout<<(x[i])<<" ";
	}
	cout<<endl;

	delete[] x; // Free x

}