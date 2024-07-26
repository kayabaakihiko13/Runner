#include <cstdlib>
#include <stdio.h>
#include "../include/Runner/rand_generator.h"

void printArr(int * arr,const int size){
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    
}

int main(void) {
    int* arr = (int*)malloc(10 *sizeof(int));
    for (int i = 0; i < 10; i++) {
        float randomVal = Randomness();
        printf("%f\n", randomVal);
    }

    for (int i = 0; i < 10; i++) {
        int randoValInt = RandomInt(10, 20);
        printf("%d\n", randoValInt);
    }
    for (int i = 0; i < 10; i++) {
        int randoValInt = RandomInt(10, 20);
        arr[i]=randoValInt;
    }
    printf("this fill:\n");
    printArr(arr, 10);
    return 0;
}
