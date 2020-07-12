#ifndef MATRIXTRANSPOSE
#define MATRIXTRANSPOSE
#include<cstddef>

namespace ra::cache {
	template <class T>
	void naive_matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b){
		for(std::size_t i=0; i<m; ++i){
			for(std::size_t j=0; j<n; ++j){
				b[j*m+i] = a[i*n+j];
			}
		}
	}


	template <class T>
	void matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b){
		static int initialized_original_lenghts = 0;
		static std::size_t orgin_m;
		static std::size_t orgin_n;
		if(!initialized_original_lenghts){
			orgin_m = m;
			orgin_n = n;
			initialized_original_lenghts = 1;
		}

		bool flag_a_is_b = false;
		T* old_b = b;
		if(b == a){ // Handle a and b being the same
			b = new T[m*n];
			flag_a_is_b = true;
		}

		// Base case
		if((m*n)<=64){
			naive_matrix_transpose(a, m, n, b);
		}
		// Recurse
		else{
			if(m >= n){ // Divide m
				std::size_t m1 = m / 2; // Number of rows in A1
				std::size_t m2 = m - m1; // Number of rows in A2
				const T* a1 = a; // pointer to first element in A1
				const T* a2 = a + (m1*n); // pointer to first element in A2
				T* b1 = b; // pointer to first element in B1
				T* b2 = b + m1; // pointer to first element in B2
				matrix_transpose(a1,m1,n,b1);
				matrix_transpose(a2,m2,n,b2);
			}
			else{
				std::size_t n1 = n / 2; // Number of columns in A1
				std::size_t n2 = n - n1; // Number of columns in A2
				const T* a1 = a; // pointer to the first element in A1
				const T* a2 = a + n1; // pointer to first element in A2
				T* b1 = b; // pointer to first element in B1
				T* b2 = b + (n1*m); // pointer to first element in B2
				matrix_transpose(a1,m,n1,b1);
				matrix_transpose(a2,m,n2,b2);
			}
		}
		
		if(flag_a_is_b){ // If a and old b were same, copy b into a and free b	
			for(std::size_t i=0; i<(m*n); ++i){
				old_b[i] = b[i];
			}
			delete[] b; 
		}
	}



}
#endif