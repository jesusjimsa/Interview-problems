# Description

A non-empty array `A` consisting of `N` integers is given.

A permutation is a sequence containing each element from `1` to `N` once, and only once.

For example, array `A` such that:
```python
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
```

is a permutation, but array A such that:
```python
    A[0] = 4
    A[1] = 1
    A[2] = 3
```

is not a permutation, because value `2` is missing.

The goal is to check whether array `A` is a permutation.

Write a function:
```python
def solution(A)
```

that, given an array `A`, returns `1` if array `A` is a permutation and `0` if it is not.

For example, given array `A` such that:
```python
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
```

the function should return `1`.

Given array `A` such that:
```python
    A[0] = 4
    A[1] = 1
    A[2] = 3
```
the function should return 0.

Write an efficient algorithm for the following assumptions:

* `N` is an integer within the range `[1..100,000]`;
* Each element of array A is an integer within the range `[1..1,000,000,000]`.

Solved in Python.

From [Codility](https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/).