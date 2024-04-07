'''
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at
both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary
representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary
representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no
binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

```
def solution(N)
```

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N
doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its
longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation
'100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range `[1..2,147,483,647]`.
'''


def solution(N):
    '''
    Find the binary gap of zeros in the binary representation of `N`.

    Parameters
    ----------
    N : Int
        Integer to find the binary gap of.

    Returns
    -------
    max_gap : Int
        Biggest gap of zeros in `N`.
    '''
    max_gap = 0
    current_gap = 0

    if N == 0:
        return 0

    binary_string = f"{N:b}"

    if '0' not in binary_string:
        return 0

    i = 0

    while i < len(binary_string):
        if binary_string[i] == '1' and (i + 1) < len(binary_string) and binary_string[i + 1] == '0':

            for j in range(i + 1, len(binary_string)):
                if binary_string[j] == '0':
                    if j < len(binary_string) - 1:
                        current_gap += 1
                    else:
                        current_gap = 0
                        i = j
                        break
                else:
                    max_gap = max(max_gap, current_gap)
                    current_gap = 0
                    i = j - 1
                    break

        i += 1

    return max_gap


print(solution(9))          # 2
print(solution(1041))       # 5
print(solution(32))         # 0
print(solution(529))        # 4
print(solution(20))         # 1
print(solution(15))         # 0
print(solution(2147483))    # 5
print(solution(328))        # 2
