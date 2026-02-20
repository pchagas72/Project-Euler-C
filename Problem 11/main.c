#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int m[20][20];
    char cursor[10];
    FILE *f;
    
    f = fopen("./number.txt", "r"); 
    if (f == NULL){
        printf("Error: Could not open file\n");
        return 1;
    }

    int i = 0, j = 0;
    while (fscanf(f, "%s", cursor) == 1) {
        if (i >= 20) {
            break;
        }

        m[i][j] = atoi(cursor); 
        j++;

        if (j == 20) {
            j = 0;  
            i++;
        }
    }
    
    fclose(f);

    int biggest = 0;
    int product = 0;
    int adj = 4;

    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            
            // Right
            if (col <= 20 - adj) {
                product = m[row][col] * m[row][col+1] * m[row][col+2] * m[row][col+3];
                if (product > biggest) biggest = product;
            }

            // Down
            if (row <= 20 - adj) {
                product = m[row][col] * m[row+1][col] * m[row+2][col] * m[row+3][col];
                if (product > biggest) biggest = product;
            }

            // Down right
            if (row <= 20 - adj && col <= 20 - adj) {
                product = m[row][col] * m[row+1][col+1] * m[row+2][col+2] * m[row+3][col+3];
                if (product > biggest) biggest = product;
            }

            // Down left
            if (row <= 20 - adj && col >= adj - 1) {
                product = m[row][col] * m[row+1][col-1] * m[row+2][col-2] * m[row+3][col-3];
                if (product > biggest) biggest = product;
            }
        }
    }
    
    printf("%d\n", biggest);
    return 0;
}
