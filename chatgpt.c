#include <stdio.h>
#include <stdlib.h>

void splitArray(const int *originalArray, int length, int numRows, int numCols, int ***splitarray) {
    // Allocate memory for the 2D array
    *splitarray = (int **)malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++) {
        (*splitarray)[i] = (int *)malloc(numCols * sizeof(int));
    }

    // Copy elements to the 2D array
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (index < length) {
                (*splitarray)[i][j] = originalArray[index++];
            } else {
                (*splitarray)[i][j] = 0;  // Or any default value you prefer
            }
        }
    }
}

int main() {
    int originalArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int length = sizeof(originalArray) / sizeof(originalArray[0]);
    int numRows = 3;
    int numCols = 4;

    int **splitarray;
    splitArray(originalArray, length, numRows, numCols, &splitarray);

    // Print the split array
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", splitarray[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < numRows; i++) {
        free(splitarray[i]);
    }
    free(splitarray);

    return 0;
}
