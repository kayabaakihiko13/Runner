#ifndef RUNNER_RAND_GENERATOR
#define RUNNER_RAND_GENERATOR

#include <time.h>
#include <stdlib.h>
#include <cstdlib>
static unsigned int seed = 0;

static unsigned int SRandom() {
    return (unsigned int)time(NULL);
}

static unsigned int randomLCG(unsigned int seed){
    return (1664525 * seed + 12345) % (1U << 31);
}

float Randomness() {
    if (seed == 0) {
        seed = SRandom();
    }
    seed = randomLCG(seed);
    return seed / (float)(1U << 31);
}

int RandomInt(int min, int max) {
    if (seed == 0) {
        seed = SRandom();
    }
    seed = randomLCG(seed);
    return min + (seed % (max - min + 1));
}
// TO DO THIS !!! belum kelar cokk
void RandomInt(int* arr,const int size,int min,int max){
    for (int i = 0; i < size; i++) {
        arr[i] = RandomInt(min, max);
    }
}


void UniformRandomArr(float* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = Randomness(); 
    }
}

#endif
