#ifndef RUNNER_UTILS
#define RUNNER_UTILS
#include <cstddef>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

struct Matrix {
    int x;
    int y;
    float* data;
};

struct Matrix make_matrix(int n_rows, int n_cols) {
    struct Matrix matrix;
    matrix.x = n_rows;
    matrix.y = n_cols;
    matrix.data = (float*)malloc(n_rows * n_cols * sizeof(int));
    return matrix;
}

void print_matrix(struct Matrix* matrix) {
    for (int i = 0; i < matrix->x; i++) {
        for (int j = 0; j < matrix->y; j++) {
            printf("%.2f ", matrix->data[i * matrix->y + j]); // Menampilkan dengan 2 desimal
        }
        printf("\n");
    }
}

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