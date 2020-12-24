/*
n the game of Minesweeper, a player has to guess the positions of
mines in a square grid. A player can click at any cell in the square
grid. If that cell contains a mine, (s)he loses the game. If that cell
does not contain a mine, then (s)he is displayed the number of
neighboring cells in which there are mines.

In this question, you are given a 7x7 array (let us denote it as A)
containing 1s and 0s. The 1s represent mines, and the 0s represent
empty cells.

You have to output a 7x7 array of integers (let us denote it by B)
with the following property:

For 0 <= i <= 6, and 0 <= j <= 6,

- if A[i][j]=1, then B[i][j]=-1
- if A[i][j]=0, then B[i][j] is equal to the number of neighboring
  cells in A which contain a 1.


Note:
1. A corner cell has exactly 3 neighbours - for example, the top left
corner cell has a right neighbour, a bottom neighbour, and a neighbour
to the bottom right.

2. A cell on an edge which is not a corner cell has exactly 5
neighbours - for example, a cell on the left edge which is not a
corner cell has a top neighbour, a top right neighbour, a right
neighbour, a bottom right neighbour, and a bottom neighbour.

3. All remaining cells have exactly eight neighbours.

Sample Test Cases
Input	Output
Test Case 1	
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
Output:
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
Test Case 2	
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1 
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
Output:
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
Test Case 3	
1 1 0 0 0 1 1 
1 0 0 0 0 0 1 
1 1 1 1 1 1 1 
0 0 0 0 0 0 0 
1 0 1 0 1 1 1 
1 0 0 0 1 1 0 
0 0 0 0 0 0 0 
Output:
-1 -1 1 0 1 -1 -1 
-1 6 4 3 4 6 -1 
-1 -1 -1 -1 -1 -1 -1 
3 5 4 5 5 6 4 
-1 3 -1 3 -1 -1 -1 
-1 3 1 3 -1 -1 3 
1 1 0 1 2 2 1 
Test Case 4	
1 0 1 0 1 0 1
1 1 0 1 1 1 1
1 1 1 1 1 1 1
0 1 1 1 1 1 0
0 0 0 0 0 0 0
0 0 0 0 0 1 1
1 0 1 1 0 0 0
Output:
-1 4 -1 4 -1 5 -1 
-1 -1 6 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 
3 -1 -1 -1 -1 -1 3 
1 2 3 3 4 4 3 
1 2 2 2 2 -1 -1 
-1 2 -1 -1 2 2 2 
Test Case 5	
0 0 0 0 0 0 0
0 0 0 1 0 0 0
0 0 1 0 1 0 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 1 1 1 0 0 
Output:
0 1 2 -1 2 1 0 
0 1 -1 4 -1 1 0 
0 1 2 -1 2 1 0 
0 0 1 1 1 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 

*/

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