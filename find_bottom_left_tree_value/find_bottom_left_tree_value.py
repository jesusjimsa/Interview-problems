"""
Given the `root` of a binary tree, return the leftmost value in the last row of the tree.

## Example 1

```
Input: root = [2,1,3]
Output: 1
```

## Example 2

```
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
```

## Constraints:

* The number of nodes in the tree is in the range `[1, 104]`
* `-2^31 <= Node.val <= 2^31 - 1`
"""

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    """
    A class representing a node in a binary tree.

    Attributes:
        val (int): The value stored in the node.
        left (Optional[TreeNode]): The left child node.
        right (Optional[TreeNode]): The right child node.
    """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """
    A class providing methods to find the bottom-left value in a binary tree.
    """
    def __init__(self, maxDepth=0, answer=0):
        """
        Initialize the Solution with default values.
        """
        self.maxDepth = maxDepth
        self.answer = answer

    def findDeepestNode(self, root: Optional[TreeNode], deepest_level=1):
        """
        Recursively find the deepest left node in the binary tree.

        Args:
            root (Optional[TreeNode]): The current node being processed.
            current_depth (int, optional): Current depth in the tree. Defaults to 1.
        """
        if root is None:
            return deepest_level

        if deepest_level > self.maxDepth:
            self.maxDepth = deepest_level
            self.answer = root.val

        self.findDeepestNode(root=root.left, deepest_level=deepest_level+1)
        self.findDeepestNode(root=root.right, deepest_level=deepest_level+1)

    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        """
        Find the bottom-left value in the binary tree.

        Args:
            root (Optional[TreeNode]): The root of the binary tree.

        Returns:
            Optional[int]: The value of the bottom-left node, or None if tree is empty.
        """
        if root is None:
            return None

        self.findDeepestNode(root=root)

        return self.answer
