/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M
starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is,
if M = 10011, you can assume that there are at least 5 bits between j and i. You would not be, for example, have j = 3
and i = 2, because M could not fully fit between bit 3 and bit 2.

Example:

Input:  N = 10000000000, M = 10011, i = 2, j = 6
Output: N = 10001001100
*/

#include <stdio.h>
#include <stdlib.h>

int32_t clearBit(int32_t num, int i) {
    int mask = ~(1 << i);

    return num & mask;
}

void printBinary(const int32_t num) {
    int32_t n = num;

    while (n) {
        if (n & 1) {
            printf("1");
        }
        else {
            printf("0");
        }

        n >>= 1;
    }

    printf("\n");
}

int32_t insertBits(int32_t N, int32_t M, int i, int j) {
    int32_t n_cleared = N;
    int32_t m_shifted = M;
    int k = 0;

    for (k = i; k <= j; k++) {
        clearBit(n_cleared, k);
    }

    m_shifted = M << i;

    return n_cleared | m_shifted;
}

int main(int argc, char **argv) {
    int32_t N = 0b10000000000;
    int32_t M = 0b10011;
    int i = 2;
    int j = 6;

    int32_t result = insertBits(N, M, i, j);

    printBinary(result);

    return 0;
}
