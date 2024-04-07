"""
    Return the longest run of 1s for a given integer n's binary representation.

    Example:
    ```
    Input: 242
    Output: 4
    ```

    `242` in binary is `0b11110010`, so the longest run of `1` is 4.
"""


def longest_run(n):
    """
    Return max number of consecutive 1s when coonverting `n` to binary

    Parameters
    ----------
    n : Int
        Number to convert to binary and get max consecutive 1s
    """
    num_in_binary = f'{n:b}'
    print(num_in_binary)
    consecutive_max = 0
    current_consecutive = 1

    for i in range(0, len(num_in_binary) - 1):
        if num_in_binary[i] == '1' and num_in_binary[i + 1] == '1':
            current_consecutive += 1
        else:
            consecutive_max = max(consecutive_max, current_consecutive)

            current_consecutive = 1

    return consecutive_max


print(longest_run(242))
# 4

print(longest_run(2015))
# 5

print(longest_run(123456765432123456543))
# 6
