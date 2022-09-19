"""
    Given an integer, convert the integer to a roman numeral. You can assume the input will be between 1 to 3999.

    The rules for roman numerals are as following:

    There are 7 symbols, which correspond to the following values.
    ```
    I   1
    V   5
    X   10
    L   50
    C   100
    D   500
    M   1000
    ```
    The value of a roman numeral are the digits added together. For example the roman numeral 'XX' is
    `V + V = 10 + 10 = 20`. Typically the digits are listed from largest to smallest, so `X` should always come before
    `I`. Thus the largest possible digits should be used first before the smaller digits (so to represent `50`, instead
    of `XXXXX`, we should use `L`).

    There are a couple special exceptions to the above rule.

    To represent `4`, we should use `IV` instead of `IIII`. Notice that `I` comes before `V`.
    To represent `9`, we should use `IX` instead of `VIIII`.
    To represent `40`, we should use `XL` instead of `XXXX`.
    To represent `90`, we should use `XC` instead of `LXXXX`.
    To represent `400`, we should use `CD` instead of `CCCC`.
    To represent `900`, we should use `CM` instead of `DCCCC`.
"""

ROMAN_ONE = 'I'
ROMAN_FIVE = 'V'
ROMAN_TEN = 'X'
ROMAN_FIFTY = 'L'
ROMAN_HUNDRED = 'C'
ROMAN_FIVE_HUNDRED = 'D'
ROMAN_THOUSAND = 'M'

ROMAN_VALUES = [
    ROMAN_ONE,
    ROMAN_FIVE,
    ROMAN_TEN,
    ROMAN_FIFTY,
    ROMAN_HUNDRED,
    ROMAN_FIVE_HUNDRED,
    ROMAN_THOUSAND
]


def integer_to_roman(num):
    """
        Converts integers from 1 to 3999 to roman numbers.

        Parameters
        ----------
        num : Int
            Number to be converted
    """
    def add_roman(step, roman):
        if roman not in ROMAN_VALUES:
            print("Not a valid roman number to be added")
            return None

        result = ''
        quantity = 0

        if step in (1, 6):
            quantity = 1
        elif step in (2, 7):
            quantity = 2
        elif step in (3, 8):
            quantity = 3

        for _ in range(0, quantity):
            result += roman

        return result

    def handle_unit(value, roman_general, roman_four, roman_five, roman_nine):
        result = ''

        if value == 4:
            result += roman_four
        elif value == 5:
            result += roman_five
        elif value == 9:
            result += roman_nine

        result += add_roman(value, roman_general)
        return result

    result = ''
    string_num = str(num)
    index = 0

    if len(string_num) == 4:
        result += add_roman(int(string_num[0]), ROMAN_THOUSAND)
        index = 1

    if len(string_num) >= 3:
        result += handle_unit(int(string_num[index]), ROMAN_HUNDRED, ROMAN_HUNDRED + ROMAN_FIVE_HUNDRED,
                              ROMAN_FIVE_HUNDRED, ROMAN_HUNDRED + ROMAN_THOUSAND)
        index += 1

    if len(string_num) >= 2:
        result += handle_unit(int(string_num[index]), ROMAN_TEN, ROMAN_TEN + ROMAN_FIFTY,
                              ROMAN_FIFTY, ROMAN_TEN + ROMAN_HUNDRED)
        index += 1

    if len(string_num) >= 1:
        result += handle_unit(int(string_num[index]), ROMAN_ONE, ROMAN_ONE + ROMAN_FIVE,
                              ROMAN_FIVE, ROMAN_ONE + ROMAN_TEN)
        index += 1

    return result


print(integer_to_roman(3))
# III
print(integer_to_roman(4))
# IV
print(integer_to_roman(1000))
# M
print(integer_to_roman(48))
# XLVIII
print(integer_to_roman(444))
# CDXLIV
print(integer_to_roman(123))
# CXXIII
print(integer_to_roman(3999))
# MMMCMXCIX
