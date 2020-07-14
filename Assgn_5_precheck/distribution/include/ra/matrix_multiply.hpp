#ifndef MATRIXMULTIPLY
#define MATRIXMULTIPLY
#include<cstddef>

namespace ra::cache {
	template <class T>
	void naive_matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c){
		for(std::size_t i=0; i<m; ++i){
			for(std::size_t j=0; j<p; ++j){
				T sum = T(0);
				for(std::size_t k=0; k<n; ++k){
					sum += a[i*n+k] * b[k*p+j];
				}
				c[i*p+j] = sum;
			}
		}
	}

	template <class T>
	void matrix_multiply_recurse(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c, std::size_t M, std::size_t N, std::size_t P, bool ac_flag){
		// Base case
		if((m*n*p)<=64){
			for(std::size_t i=0; i<m; ++i){
				for(std::size_t j=0; j<p; ++j){
					T sum = T(0);
					for(std::size_t k=0; k<n; ++k){
						sum += a[i*N+k] * b[k*P+j];
					}
					if(ac_flag){ c[i*P+j] += sum; }
					else{ c[i*P+j] = sum; }
				}
			}
		}
		// Recurse
		else{
			if(m>=n && m>=p){ // Divide dimension m (Case 1)
				std::size_t m1 = m/2; // Number of rows in A1 and C1
				std::size_t m2 = m - m1; // Number of rows in A2 and C2
				const T* a1 = a; // pointer to first element in A1
				const T* a2 = a + (m1*N); // pointer to first element in A2
				T* c1 = c; // pointer to first element in C1
				T* c2 = c + (m1*P); // pointer to first element in C2
				matrix_multiply_recurse(a1, b, m1, n, p, c1, M, N, P, ac_flag);
				matrix_multiply_recurse(a2, b, m2, n, p, c2, M, N, P, ac_flag);
			}
			else if(n>=m && n>=p){ // Divide dimension n (Case 2)
				std::size_t n1 = n/2; // Number of columns in A1 and number of rows in B1
				std::size_t n2 = n - n1; // Number of columns in A2 and number of rows in B2
				const T* a1 = a; // pointer to first element in A1
				const T* a2 = a + n1; // pointer to first element in A2
				const T* b1 = b; // pointer to first element in B1
				const T* b2 = b + (n1*P); // pointer to first element in B2
				matrix_multiply_recurse(a1, b1, m, n1, p, c, M, N, P, ac_flag);
				matrix_multiply_recurse(a2, b2, m, n2, p, c, M, N, P, true);
			}
			else{ // Divide dimension p (Case 3)
				std::size_t p1 = p/2; // Number of columns in B1 and C1
				std::size_t p2 = p - p1; // Number of columns in B2 and C2
				const T* b1 = b; // pointer to first element in B1
				const T* b2 = b + p1; // pointer to first element in B2
				T* c1 = c; // pointer to first element in C1
				T* c2 = c + p1; // pointer to first element in C2
				matrix_multiply_recurse(a, b1, m, n, p1, c1, M, N, P, ac_flag);
				matrix_multiply_recurse(a, b2, m, n, p2, c2, M, N, P, ac_flag);
			}
		}
	}


	template <class T>
	void matrix_multiply(const T* a, const T* b, std::size_t m, std::size_t n, std::size_t p, T* c){
		matrix_multiply_recurse(a,b,m,n,p,c,m,n,p,false);
	}


}
#endif
