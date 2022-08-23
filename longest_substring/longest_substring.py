'''
Given a string, find the length of the longest substring without repeating characters.

Can you find a solution in linear time?
'''


def lengthOfLongestSubstring(s):
    '''
        Find lenght of longest substring with no repeatinng characters
    '''
    res = 0

    for i in range(0, len(s)):
        visited = []

        for j in range(i, len(s)):
            if s[j] in visited:
                break

            res = max(res, j - i + 1)
            visited.append(s[j])

    return res


print(lengthOfLongestSubstring('abrkaabcdefghijjxxx'))
# 10
