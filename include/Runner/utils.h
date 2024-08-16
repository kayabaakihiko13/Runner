#ifndef RUNNER_UTILS
#define RUNNER_UTILS
#include <cstddef>
#include <stdio.h>
#include <cstdlib>
#include <ctime>




void printArrInt(int * arr,const int size){
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    
}
void printArrFloat(float * arr,const int size){
    for (int i = 0; i < size; i++) {
        printf("%f\n", arr[i]);
    }
    
}

void Print2DArr(int **arr, const int row_size, const int col_size) {
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
#endif