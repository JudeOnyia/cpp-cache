#include "ra/matrix_transpose.hpp"
#include<iostream>
#include<cstddef>
#include<complex>

int main(){
	using std::cout;
	using std::endl;
	using type_t = double;

	std::size_t rows;
	std::size_t cols;
	rows = 10;
	cols = 17;

	// Creating matrix[rows][cols]
	type_t* matrx = new type_t[rows*cols];

	// Creating result[cols][rows]
	type_t* result = new type_t[cols*rows];

	// Creating naive_result[cols][rows]
	type_t* naive_result = new type_t[cols*rows];

	// Initialize matrix and result and naive result
	for(std::size_t i=0; i<rows; ++i){
		for(std::size_t j=0; j<cols; ++j){
			matrx[i*cols+j] = i*cols+j;
			result[j*rows+i] = 0;
			naive_result[j*rows+i] = 0;
		}
	}

	// TEST Transpose matrix where the original matrix and resulting matrix are different
	cout << "TEST Transpose matrix (Different)"<<endl;
	ra::cache::matrix_transpose<type_t>(matrx,rows,cols,result);
	
	// Print matrix
	for(std::size_t i=0; i<rows; ++i){
		for(std::size_t j=0; j<cols; ++j){
			cout<<matrx[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	// Print result
	for(std::size_t i=0; i<cols; ++i){
		for(std::size_t j=0; j<rows; ++j){
			cout<<result[i*rows+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;


	// TEST Naive_Transpose matrix
	cout << "TEST Naive Transpose matrix"<<endl;
	ra::cache::naive_matrix_transpose<type_t>(matrx,rows,cols,naive_result);

	// Print naive_result
	for(std::size_t i=0; i<cols; ++i){
		for(std::size_t j=0; j<rows; ++j){
			cout<<naive_result[i*rows+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;


	// TEST Transpose matrix where the original matrix and resulting matrix are the same
	cout<< "TEST Transpose matrix (in-place)" <<endl;
	ra::cache::matrix_transpose<type_t>(matrx,rows,cols,matrx);

	// Print matrix in-place transposed
	for(std::size_t i=0; i<cols; ++i){
		for(std::size_t j=0; j<rows; ++j){
			cout<<matrx[i*rows+j]<<" ";
		}
		cout<<endl;
	}

	// Delete matrix and result
	delete[] matrx;
	delete[] result;
	delete[] naive_result;




}
