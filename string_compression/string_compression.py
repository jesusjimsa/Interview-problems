"""
    Implement a method to perform basic string compression using the counts of repeated characters. For example, the
    string `aabcccccaaa` would become `a2b1c5a3`. If the "compressed" string would not become smaller than the original
    string, your method should return the original string. You can assume the string has only uppercase and lowercase
    letters (a-z).
"""


def string_compression(input_str):
    """
        Compress string using the counts of repeated characters.

        Parameters
        ----------
        input_str : str
            String to compress.
    """
    result = input_str[0]
    num_compressed = 0

    for elem in input_str:
        if elem == result[-1]:
            num_compressed += 1
        else:
            result += str(num_compressed)
            result += elem
            num_compressed = 1

    result += str(num_compressed)

    if len(result) >= len(input_str):
        result = input_str

    return result


print(string_compression('aabcccccaaa'))
# a2b1c5a3

print(string_compression('abcdefghijklm'))
# abcdefghijklm
