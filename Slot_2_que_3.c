#include <stdio.h>
#include <stdlib.h>
#define count 7

int main(void) {
    int a[count][count], b[count][count];
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            int count_of_neighbours;
            if (a[i][j] == 1) {
                b[i][j] = -1;
            }
            else {
                count_of_neighbours = 0;
                if (i > 0 && a[i - 1][j] == 1) {
                    count_of_neighbours++;
                }
                if (i > 0 && j > 0 && a[i - 1][j - 1] == 1) {
                    count_of_neighbours++;
                }
                if (j > 0 && a[i][j - 1] == 1) {
                    count_of_neighbours++;
                }
                if (i < count - 1 && a[i + 1][j] == 1) {
                    count_of_neighbours++;
                }
                if (j < count - 1 && a[i][j + 1] == 1) {
                    count_of_neighbours++;
                }
                if (j < count - 1 && i < count - 1 && a[i + 1][j + 1] == 1) {
                    count_of_neighbours++;
                }
                if (i > 0 && j < count - 1 && a[i - 1][j + 1] == 1) {
                    count_of_neighbours++;
                }
                if (j > 0 && i < count - 1 && a[i + 1][j - 1] == 1) {
                    count_of_neighbours++;
                }
                b[i][j] = count_of_neighbours;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {

            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}