/**
    Given a sorted array of `n` integers that has been rotated an unknown number of times, write code to find an element
    in the array. You may assume that the array was originally sorted in increasing order.

    EXAMPLE

    Input: find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
    Output: 8 (the index of 5 in the array)
*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> vec, int x) {
    int low = 0;
    int high = vec.size() - 1;
    int mid = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (vec[mid] < x) {
            low = mid + 1;
        }
        else if (vec[mid] > x) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int main(){
    vector <int> vec;
    int result = 0;

    vec.push_back(15);
    vec.push_back(16);
    vec.push_back(19);
    vec.push_back(20);
    vec.push_back(25);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(10);
    vec.push_back(14);
}
