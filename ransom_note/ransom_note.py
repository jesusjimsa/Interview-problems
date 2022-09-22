"""
    A criminal is constructing a ransom note. In order to disguise his handwriting, he is cutting out letters from a
    magazine.

    Given a magazine of letters and the note he wants to write, determine whether he can construct the word.

    Can you do this in linear time?
"""


def canSpell(magazine, note):
    """
    Determine if the magazine has the required letter to make the ransom note.

    Parameters
    ----------
    magazine : List
        Letters available in the magazine.
    note : String
        Note we want to build.
    """
    for elem in note:
        if elem not in magazine:
            return False
        else:
            magazine.remove(elem)   # Remove only removes the first matching element

    return True


print(canSpell(['a', 'b', 'c', 'd', 'e', 'f'], 'bed'))
# True

print(canSpell(['a', 'b', 'c', 'd', 'e', 'f'], 'cat'))
# False

print(canSpell(['a', 'b', 'c', 'd', 'e', 'f'], 'beef'))
# False, we would need two 'e'
