#include "opencv/cv.h"

#include "expofuse.h"

double Adata[9] = {1., 2., 3., 4., 5., 6., 7., 8., 9.};
double Bdata[9] = {9., 8., 7., 6., 5., 4., 3., 2., 1.};
double Cdata[9] = {2., 2., 2., 2., 2., 2., 2., 2., 2.};
double Gdata[9] = {2., 2., 2., 2., 2., 2., 2., 2., 2.};
Matrix A = { .rows=3, .cols=3, .data = Adata };
Matrix B = { .rows=3, .cols=3, .data = Bdata };
Matrix C = { .rows=3, .cols=3, .data = Cdata };

int main(int argc, char* argv[]){
  int i;
  Matrix* D = NewMatrix(3, 3);
  for(i=0; i<3*3; i++) D->data[i] = (i-4.5)*.3;
  printf("D\n");PrintMatrix(D);
  _asmAbs(D->data, 3, 3);
  printf("D\n");PrintMatrix(D);
	return 0;
}
