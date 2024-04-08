'''
A non-empty array `A` consisting of `N` integers is given. The array contains an odd number of elements, and each
element of the array can be paired with another element that has the same value, except for one element that is left
unpaired.

For example, in array A such that:

```
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
```

* The elements at indexes `0` and `2` have value `9`,
* The elements at indexes `1` and `3` have value `3`,
* The elements at indexes `4` and `6` have value `9`,
* The element at index `5` has value `7` and is unpaired.

Write a function:

```
def solution(A)
```

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired
element.

For example, given array A such that:
```
  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
```

the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

* N is an odd integer within the range `[1..1,000,000]`;
* Each element of array A is an integer within the range `[1..1,000,000,000]`;
* All but one of the values in `A` occur an even number of times.
'''

def solution(A):
    '''
    Return the number that is left unpaired.

    Parameters
    ----------
    A : List
        Array with odd number of elements and one unpaired number.

    Returns
    -------
    sol : Int
        Unpaired number in `A`.
    '''
    # Return error if length is not correct or if array is empty
    if len(A) % 2 == 0 or not A:
        return -1

    already_checked = []
    sol = -1

    for number in A:
        if number in already_checked:
            pass
        elif A.count(number) % 2 != 0:
            sol = number
            break
        else:
            already_checked.append(number)

    return sol


def optimal_solution(A):
    '''
    Return the number that is left unpaired.

    This solution was found online after my own solution failed to run before the timeout in some test cases.

    Parameters
    ----------
    A : List
        Array with odd number of elements and one unpaired number.

    Returns
    -------
    result : Int
        Unpaired number in `A`.
    '''
    result = 0

    for number in A:
        result ^= number

    return result

print(solution([9, 3, 9, 3, 9, 7, 9]))
print(optimal_solution([9, 3, 9, 3, 9, 7, 9]))
