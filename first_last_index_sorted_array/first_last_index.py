'''
Given a sorted array, A, with possibly duplicated elements, find the indices of the first and last occurrences of a
target element, `x`. Return `-1` if the target is not found.

Example:
    Input: A = [1, 3, 3, 5, 7, 8, 9, 9, 9, 15], target = 9
    Output: [6, 8]

    Input: A = [100, 150, 150, 153], target = 150
    Output: [1, 2]

    Input: A = [1, 2, 3, 4, 5, 6, 10], target = 9
    Output: [-1, -1]
'''


class Solution:
    def getRange(self, arr, target):
        first = -1
        last = -1

        if target not in arr:
            return [first, last]

        for i in range(0, len(arr)):
            if arr[i] == target:
                first = i
                break

        for j in range(len(arr) - 1, first, -1):
            if arr[j] == target:
                last = j
                break

        return [first, last]


# Test program
arr = [1, 2, 2, 2, 2, 3, 4, 7, 8, 8]
x = 2

print(Solution().getRange(arr, x))
# [1, 4]
