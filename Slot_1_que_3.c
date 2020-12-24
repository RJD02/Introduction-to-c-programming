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