#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "../include/Runner/rand_bit_mt1997.h"

int main() {
    MT19937 rng;
    rng.seed(); // Seed with current time
    for(int i=0;i<10;i++){
        float random_value = rng.rand();
        printf("%f\n",random_value);

    }
    return 0;
}