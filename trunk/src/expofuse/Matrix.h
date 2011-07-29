#ifndef MATRIX_H
#define MATRIX_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define min(x1,x2) ((x1) > (x2) ? (x2):(x1))
#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#define forn(i,n) for((i)=0;(i)<(n);(i)++)
#define ELEM(A,i,j) (A)->data[ (i)*(A)->cols + (j) ]

typedef enum {SYMMETRIC,CIRCULAR,REPLICATE} BOUNDARY_OPTION;

typedef struct
{
	int cols;
	int rows;
	double* data;
} Matrix;

Matrix* NewMatrix(int rows, int cols);
void DeleteMatrix(Matrix* A);
Matrix* CopyMatrix(const Matrix* A);
Matrix* Substract(const Matrix* A, const Matrix* B);
Matrix* AddMatrix(const Matrix* A, const Matrix* B);
Matrix* AddEqualsMatrix(Matrix* A, const Matrix* B);
Matrix* Convolve(const Matrix* A, const Matrix* kernel, const BOUNDARY_OPTION bound);
void PrintMatrix(const Matrix* A);
void PrintMatrixMatStyle(const Matrix* A);

extern void asmInvertir(Matrix* A);

extern const Matrix LAPLACIAN_KERN_3x3;
extern const Matrix GAUSS_KERN_5x1;
extern const Matrix GAUSS_KERN_1x5;

#endif
