# Description

Write a function:
```python
def solution(A, B, K)
```

that, given three integers `A`, `B` and `K`, returns the number of integers within the range `[A..B]` that are divisible by `K`, i.e.:
```python
{ i : A ≤ i ≤ B, i mod K = 0 }
```

For example, for `A = 6`, `B = 11` and `K = 2`, your function should return `3`, because there are three numbers divisible by `2` within the range `[6..11]`, namely `6`, `8` and `10`.

Write an efficient algorithm for the following assumptions:

* `A` and `B` are integers within the range `[0..2,000,000,000]`;
* `K` is an integer within the range `[1..2,000,000,000]`;
* `A ≤ B`.

Solved in Python.

From [Codility](https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/).
