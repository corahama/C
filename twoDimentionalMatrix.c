#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 1024

typedef struct {
  double data[MAXDATA];
  int nrows;
  int ncols;
} Matrix;

void printMat(Matrix M);
void printRow(Matrix M, int row);
void printCol(Matrix M, int col);
double setElement(Matrix A, Matrix B, int row, int col);
double getElement(Matrix M, int row, int col);
Matrix matrixMul(Matrix A, Matrix B);

int main(int argc, char *argv[])
{
  Matrix B = { {1.2, 2.3,
                3.4, 4.5,
                5.6, 6.7},
               3,
               2};
  Matrix A = { {5.5, 6.6, 7.7, 2.2, 3.3,
                1.2, 2.1, 3.3, 2.5, 6.4},
               2,
               5};
  printMat(A);
  printMat(B);

  Matrix C = matrixMul(A, B);
  printMat(C);

  return 0;
}


void printMat(Matrix M){
  for (int count = 0; count < M.nrows*M.ncols; count++){
    printf("%4.1f ", M.data[count]);

    if ((count + 1) % M.ncols == 0){
      printf("\n");
    }
  }

  printf("\n");
}

void printRow(Matrix M, int row){
  int count = (row-1)*M.ncols;

  do{
      printf("%.1f ", M.data[count]);
  }while(++count % M.ncols != 0);

  printf("\n");
}

void printCol(Matrix M, int col){
  for (int count = col-1; count < M.ncols*M.nrows; count+=M.ncols){
      printf("%.1f ", M.data[count]);
  }

  printf("\n");
}

Matrix matrixMul(Matrix A, Matrix B){
  Matrix C;
  C.nrows = A.nrows;
  C.ncols = B.ncols;

  if (A.ncols != B.nrows){
    printf("Error: matrices incompatibles\n");

    return C;
  }

  for (int count = 0; count < C.nrows*C.ncols; count++)
    C.data[count] = setElement(A, B, (int)count/C.ncols, count%C.ncols);

  return C;
}

double setElement(Matrix A, Matrix B, int row, int col){
  double value = 0;

  for (int count = 0; count < A.ncols; count++)
      value += getElement(A, row, count)*getElement(B, count, col);

  return value;
}

double getElement(Matrix M, int row, int col){
  double e = M.data[row * M.ncols + col];

  return e;
}


//Otra manera de hacer la multiplicacion matricial

// Matrix matrixmult(Matrix A, Matrix B)
// {
//   // fill in the code here
//   // printf("so far matrixmult does nothing\n");
//   Matrix C;
//   if (A.ncols != B.nrows) {
//     printf("error: ncols of A does not equal nrows of B\n");
//   }
//   else {
//     int i, j, k;
//     double count;
//     for (i=0; i<A.nrows; i++) {
//       for (j=0; j<B.ncols; j++) {
// 	count = 0.0;
// 	for (k=0; k<A.ncols; k++) {
// 	  count += A.data[i*A.ncols + k] * B.data[k*B.ncols + j];
// 	}
// 	C.data[i*A.nrows + j] = count;
//       }
//     }
//     C.nrows = A.nrows;
//     C.ncols = B.ncols;
//   }
//   return C;
// }
