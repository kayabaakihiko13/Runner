#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "../include/Runner/rand_bit_mt1997.h"
#include "../include/Runner/utils.h"

int main() {
    MT19937 rng;
    rng.seed(); // Seed with current time
    // for(int i=0;i<10;i++){
    //     float random_value = rng.rand();
    //     printf("%f\n",random_value);

    // };
    // make matrix 2D
    struct Matrix mat = make_matrix(3, 3);
    for(int i =0;i<mat.x;i++){
        for(int j=0;j<mat.y;j++){
            double val = (double)rng.rand();
            mat.data[i*mat.y+j] = val;
        }
    }
    print_matrix(&mat);
    free(mat.data);
    return 0;
}