#ifndef RAND_BIT_MT19937
#define RAND_BIT_MT19937

#include <cstdint>
#include <ctime>

struct MT19937 {
private:
    static const int N = 624;
    static const int M = 397;
    static const uint32_t MATRIX_A = 0x9908b0dfUL;
    static const uint32_t UPPER_MASK = 0x80000000UL;
    static const uint32_t LOWER_MASK = 0x7fffffffUL;

    uint32_t mt[N];
    int mti;

    void twist() {
        for (int i = 0; i < N; i++) {
            uint32_t x = (mt[i] & UPPER_MASK) + (mt[(i + 1) % N] & LOWER_MASK);
            uint32_t xA = x >> 1;
            if (x & 1) {
                xA ^= MATRIX_A;
            }
            mt[i] = mt[(i + M) % N] ^ xA;
        }
        mti = 0;
    }

public:
    MT19937() : mti(N + 1) {}

    void seed(uint32_t s) {
        mt[0] = s;
        for (mti = 1; mti < N; mti++) {
            mt[mti] = 1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti;
        }
    }

    void seed() {
        seed(static_cast<uint32_t>(time(nullptr)));
    }

    uint32_t extract() {
        if (mti >= N) {
            if (mti == N + 1) {
                seed(5489UL);
            }
            twist();
        }

        uint32_t y = mt[mti++];
        y ^= (y >> 11);
        y ^= (y << 7) & 0x9d2c5680UL;
        y ^= (y << 15) & 0xefc60000UL;
        y ^= (y >> 18);

        return y;
    }

    float rand() {
        return static_cast<float>(extract()) / 4294967296.0f;
    }

    static float staticRand() {
        static MT19937 staticInstance;
        return staticInstance.rand();
    }
};

#endif // RAND_BIT_MT19937