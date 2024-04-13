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

int search_aux(vector<int> vec, int left, int right, int target) {
    int mid = (left + right) / 2;

    if (right < left) {
        return -1;  // Not found
    }

    if (target == vec[mid]) {
        return mid; // Found
    }

    if (vec[left] < vec[mid]) {
        if (vec[left] <= target && target < vec[mid]) {
            return search_aux(vec, left, mid - 1, target);
        }
        else {
            return search_aux(vec, mid + 1, right, target);
        }
    }
    else if (vec[mid] < vec[right]) {
        if (vec[mid] < target && target <= vec[right]) {
            return search_aux(vec, mid + 1, right, target);
        }
        else {
            return search_aux(vec, left, mid - 1, target);
        }
    }
    else {
        int location = -1;

        if (vec[left] == vec[mid]) {
            location = search_aux(vec, mid + 1, right, target);
        }

        if (location == -1 && vec[mid] == vec[right]) {
            location = search_aux(vec, left, mid - 1, target);
        }

        return location;
    }

    return -1;
}

int search(vector<int> vec, int target) {
    return search_aux(vec, 0, vec.size() - 1, target);
}

int main(){
    vector <int> vec;

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

    cout << "The position of 5 in the vector is " << search(vec, 5) << endl;
}
