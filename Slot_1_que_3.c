/*
A complex number is represented as a pair of floating point numbers
- (a,b) represents the complex number a+ib, where i is the square root
of -1.


You are given a 3x3 matrix (let us call it M) of such complex
numbers. The matrix is called Hermetian if for every row i and column
j, M[i][j] is the conjugate of M[j][i]. That is to say, if M[i][j]
represents the complex number a+ib, then M[j][i] should represent the
complex number a-ib.

You must output the number of entries M[i][j] such that M[i][j] is NOT
the transpose of M[j][i]. (If the matrix is actually Hermetian, then
this number will be 0.)

Hint: You can use

      scanf("(%f %f) ",&x, &y);

to read a pair of floating point numbers in the given format into
  float variables x and y. Please note that there is a space after the
  closing bracket ')' and the closing double quote
*/

#include<stdio.h>
#include<stdlib.h>
#define count 3

struct Matrix {
	int x, y;
};

typedef struct Matrix Matrix;

void display(Matrix a[count][count]) {
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            printf("(%d %d) ", a[i][j].x, a[i][j].y);
        }
        printf("\n");
    }
}

//x + iy.
//Conjugate: x - iy.
int main() {
  Matrix m[count][count];
  for(int i = 0; i < count; i++) {
    for(int j = 0; j < count; j++) {
		scanf("(%d %d) ",&m[i][j].x, &m[i][j].y);
    }
  }
  display(m);
  int no_of_conjugates = 0;
  for(int i = 0; i < count; i++) {
    for(int j = i + 1; j < count; j++) {
		if(m[i][j].x == m[j][i].x && m[i][j].y == -m[i][j].y) {
          no_of_conjugates++;
        }
    }
  }
  printf("Number of conjugates = %d\n", no_of_conjugates);
  printf("%d", count * count - 2 * no_of_conjugates);
  return 0;
}