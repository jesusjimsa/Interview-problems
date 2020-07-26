/*
    Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in
    their binary representation.
*/

#include <stdio.h>
#include <stdlib.h>

void printBinary(const int32_t num) {
    int32_t n = num;
    
    if (n < 0) {
        printf("\n");
        return;
    }

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

uint32_t nextSmallest(uint32_t num) {
    uint32_t result = 0;
    uint32_t temp = num;
    uint32_t c0 = 0;
    uint32_t c1 = 0;

    while ((temp & 1) == 1) {
        c1++;
        temp >>= 1;
    }

    if (temp == 0) {
        return -1;
    }

    while (((temp & 1) == 0) && (temp != 0)) {
        c0++;
        temp >>= 1;
    }

    uint32_t p = c0 + c1;
    result &= ((~0) << (p + 1));

    uint32_t mask = (1 << (c1 + 1)) - 1;
    result |= mask << (c0 - 1);

    return result;
}

uint32_t nextLargest(uint32_t num) {
    uint32_t result = 0;
    uint32_t c = num;
    uint32_t c0 = 0;
    uint32_t c1 = 0;

    while (((c & 1) == 0) && (c != 0)) {
        c0++;
        c >>= 1;
    }

    while ((c & 1) == 1) {
        c1++;
        c >>= 1;
    }

    if (c0 + c1 == 31 || c0 + c1 == 0) {
        return -1;
    }

    uint32_t p = c0 + c1;

    result |= (1 << p);
    result &= ~((1 << p) - 1);
    result |= (1 << (c1 - 1)) - 1;

    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("You must provide a positive integer.\n");
        return -1;
    }

    uint32_t positive_integer = (uint32_t)atoi(argv[1]);

    printf("Your number: %d\n", positive_integer);
    printf("Your number in binary (reversed): ");
    printBinary(positive_integer);

    uint32_t largest = nextLargest(positive_integer);
    uint32_t smallest = nextSmallest(positive_integer);

    printf("\nLargest: %d\n", largest);
    printBinary(largest);

    printf("Smallest: %d\n", smallest);
    printBinary(smallest);
    
    return 0;
}