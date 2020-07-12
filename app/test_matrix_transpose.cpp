#include "ra/matrix_transpose.hpp"
#include<iostream>

int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	using type_t = double;

	std::size_t rows;
	std::size_t cols;
	rows = 10;//cin>>rows;
	cols = 10;//cin>>cols;

	type_t** matrx = new type_t*[rows];
	for(std::size_t i=0; i<rows; ++i){
		matrx[i] = new type_t[cols];
	}

	type_t** result = new type_t*[cols];
	for(std::size_t i=0; i<cols; ++i){
		result[i] = new type_t[rows];
	}

	for(std::size_t i=0; i<rows; ++i){
		for(std::size_t j=0; j<cols; ++j){
			matrx[i][j] = i*j+1;//cin>>matrx[i][j];
		}
	}

	const type_t* a = &(matrx[0][0]);
	type_t* b = &(result[0][0]);

	ra::cache::matrix_transpose<type_t>(a,rows,cols,b);
	
	for(std::size_t i=0; i<rows; ++i){
		for(std::size_t j=0; j<cols; ++j){
			cout<<matrx[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;

	for(std::size_t i=0; i<cols; ++i){
		for(std::size_t j=0; j<rows; ++j){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}




}
