#include "ra/matrix_multiply.hpp"
#include<iostream>
#include<cstddef>

int main(){
	using std::cout;
	using std::endl;
	using type_t = double;

	std::size_t M = 10;
	std::size_t N = 7;
	std::size_t P = 4;

	// Creating A[M][N]
	type_t* A = new type_t[M*N];

	// Creating B[N][P]
	type_t* B = new type_t[N*P];

	// Creating C[M][P]
	type_t* C = new type_t[M*P];

	// Creating naive_C[M][P]
	type_t* naive_C = new type_t[M*P];

	// Initialize A and display it
	cout<<"Matrix A"<<endl;
	for(std::size_t i=0; i<M; ++i){
		for(std::size_t j=0; j<N; ++j){
			A[i*N+j] = i*N+j;
			cout<<(A[i*N+j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	// Initialize B and display it
	cout<<"Matrix B"<<endl;
	for(std::size_t i=0; i<N; ++i){
		for(std::size_t j=0; j<P; ++j){
			B[i*P+j] = i*P+j;
			cout<<(B[i*P+j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	// Initialize C and naive_C and display C
	cout<<"Matrix C"<<endl;
	for(std::size_t i=0; i<M; ++i){
		for(std::size_t j=0; j<P; ++j){
			C[i*P+j] = i*P+j;
			cout<<(C[i*P+j])<<" ";
			naive_C[i*P+j] = i*P+j;
		}
		cout<<endl;
	}
	cout<<endl;

	// Test Matrix Multiplication
	cout << "Test Matrix Multiplication" << endl << endl;
	ra::cache::matrix_multiply<type_t>(A, B, M, N, P, C);

	// Test Naive Matrix Multiplication
	cout << "Test Naive Matrix Multiplication" << endl << endl;
	ra::cache::naive_matrix_multiply(A, B, M, N, P, naive_C);

	// Display C
	cout<<"Matrix C"<<endl;
	for(std::size_t i=0; i<M; ++i){
		for(std::size_t j=0; j<P; ++j){
			cout<<(C[i*P+j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	// Display naive_C
	cout<<"Matrix naive_C"<<endl;
	for(std::size_t i=0; i<M; ++i){
		for(std::size_t j=0; j<P; ++j){
			cout<<(naive_C[i*P+j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	// Free
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] naive_C;




}
