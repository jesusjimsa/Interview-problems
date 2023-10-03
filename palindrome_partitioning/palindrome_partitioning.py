"""
Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return _all possible
palindrome partitioning of `s`_.


#### Example 1:

> **Input:** `s = "aab"`
> **Output:** `[["a","a","b"],["aa","b"]]`

#### Example 2:

> **Input:** `s = "a"`
> **Output:** `[["a"]]`


#### Constraints:

* `1 <= s.length <= 16`
* `s` contains only lowercase English letters.
"""


def partition(s: str):
    """
    Returns all possible palindrome partitioning of `s`.

    Parameters
    ----------
    s : str
        String to partition.
    Returns
    -------
    result : list(list(str))
        List with a list of all possible palindrome partitioning of `s`.
    """
    result = list([])

    result.append(list(s))  # The first list contains each separate character

    if len(s) == 1:
        return result

    for i in range(2, len(s) + 1):
        s_copy = s
        tmp_list = []
        j = 0
        max_tries = len(s) - i + 1

        while len(s_copy) > 0 and j < len(s_copy) and max_tries > 0:
            s_chunk = s_copy[j:j+i]

            if s_chunk == s_chunk[::-1]:    # s_chunk == reversed(s_chunk)
                tmp_list.append(s_chunk)
                s_copy = s_copy.replace(s_chunk, "", 1)
            else:
                j += 1

            max_tries -= 1

        if len(s_copy) > 0 and len(tmp_list) > 0:
            for k in range(0, len(s_copy)):
                tmp_list.append(s_copy[k])

            result.append(tmp_list)
        elif len(tmp_list) > 0:
            result.append(tmp_list)

    return result


print(partition("aab"))
print(partition("a"))
print(partition("bb"))
print(partition("cdd"))
print(partition("efe"))
