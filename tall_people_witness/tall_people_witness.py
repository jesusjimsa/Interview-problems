"""
    There are n people lined up, and each have a height represented as an integer. A murder has happened right in front
    of them, and only people who are taller than everyone in front of them are able to see what has happened. How many
    witnesses are there?

    Example:
    ```
    Input: [3, 6, 3, 4, 1]
    Output: 3
    ```

    Explanation: Only `[6, 4, 1]` were able to see in front of them.
    ```
    #
    #
    # #
    ####
    ####
    #####
    36341                                 x (murder scene)
    ```
"""


def witnesses(heights):
    """
    Returns the number of people who were able to see the murder.

    It reverses the list and adds one person each time they are taller than the previous tallest one.

    Parameters
    ----------
    heights : List
        List of heights
    """
    previous_tallest = heights[-1]
    num_witnesses = 1

    heights.reverse()

    for person in heights:
        if person > previous_tallest:
            previous_tallest = person
            num_witnesses += 1

    return num_witnesses


print(witnesses([3, 6, 3, 4, 1]))
# 3

print(witnesses([3, 12, 6, 3, 4, 1]))
# 4

print(witnesses([3, 6, 12, 3, 4, 1]))
# 3
