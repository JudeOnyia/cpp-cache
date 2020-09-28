# cpp-cache
Several implementations are involved in this project:

1)  a function template is developed that performs a matrix transposition using a particular cache-oblivious
algorithm. Given an m×n matrix A, we wish to compute B = A'(where B is an n×m matrix). (Note that, as a matter of
notation, an m×n matrix is a matrix with m rows and n columns.)

2)  a function template developed that performs matrix multiplication using a particular cache-oblivious algorithm.
Given an m×n matrix A and an n× p matrix B, we wish to compute the matrix product C = AB, where C is m×p. (Note that,
as a matter of notation, an m×n matrix is a matrix with m rows and n columns.)

3)  a function template is developed that computes a fast-Fourier transform (FFT) using a particular cache-oblivious
algorithm.
