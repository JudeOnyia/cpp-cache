#ifndef MATRIXTRANSPOSE
#define MATRIXTRANSPOSE

namespace ra::cache {
	template <class T>
	void matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b);


	template <class T>
	void naive_matrix_transpose(const T* a, std::size_t m, std::size_t n, T* b);

}
#endif