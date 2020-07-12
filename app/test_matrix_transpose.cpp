#include "ra/matrix_transpose.hpp"
#include<iostream>
#include<cstddef>

int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	using type_t = double;

	std::size_t rows;
	std::size_t cols;
	rows = 6;//cin>>rows;
	cols = 5;//cin>>cols;

	// Creating matrix[rows][cols]
	type_t* matrx = new type_t[rows*cols];

	// Creating result[cols][rows]
	type_t* result = new type_t[cols*rows];

	// Initialize matrix and result
	for(std::size_t i=0; i<rows; ++i){
		for(std::size_t j=0; j<cols; ++j){
			matrx[i*cols+j] = i*cols+j;//cin>>matrx[i][j];
			result[j*rows+i] = 0;
		}
	}

	// Transpose matrix
	ra::cache::matrix_transpose<type_t>(matrx,rows,cols,result);
	
	// Print matrix
	for(std::size_t i=0; i<rows; ++i){
		for(std::size_t j=0; j<cols; ++j){
			cout<<matrx[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;

	// Print result
	for(std::size_t i=0; i<cols; ++i){
		for(std::size_t j=0; j<rows; ++j){
			cout<<result[i*rows+j]<<" ";
		}
		cout<<endl;
	}

	// Delete matrix and result
	delete[] matrx;
	delete[] result;




}
