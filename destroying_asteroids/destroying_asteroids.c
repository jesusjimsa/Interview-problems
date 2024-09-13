/*
    You are given an integer `mass`, which represents the original mass of a planet. You are further given an integer
    array `asteroids`, where `asteroids[i]` is the mass of the `ith` asteroid.

    You can arrange for the planet to collide with the asteroids in **any arbitrary order**. If the mass of the planet
    is **greater than or equal to** the mass of the asteroid, the asteroid is **destroyed** and the planet **gains** the
    mass of the asteroid. Otherwise, the planet is destroyed.

    Return `true` if **all** *asteroids can be destroyed*. Otherwise, return `false`.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Comparison function
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    long long int current_planet_mass = mass;
    int i = 0;

    qsort(asteroids, asteroidsSize, sizeof(int), compare);

    for (i = 0; i < asteroidsSize; i++) {
        if (current_planet_mass < asteroids[i]) {
            return false;
        }

        current_planet_mass += asteroids[i];
    }

    return true;
}

int main(int argc, char const *argv[]) {
    int arr1[] = {3, 9, 19, 5, 21};
    int mass1 = 10;
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("%s\n", asteroidsDestroyed(mass1, arr1, size1) ? "All asteroids are destroyed" : "The planet is destroyed");

    int arr2[] = {4, 9, 23, 4};
    int mass2 = 5;
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("%s\n", asteroidsDestroyed(mass2, arr2, size2) ? "All asteroids are destroyed" : "The planet is destroyed");

    return 0;
}
