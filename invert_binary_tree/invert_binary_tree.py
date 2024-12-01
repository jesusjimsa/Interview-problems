"""
Given the `root` of a binary tree, invert the tree, and return *its root*.

## Example 1

```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
```

## Example 2

```
Input: root = [2,1,3]
Output: [2,3,1]
```

## Example 3

```
Input: root = []
Output: []
```

## Constraints:

* The number of nodes in the tree is in the range `[0, 100]`
* `-100 <= Node.val <= 100`
"""

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    """Represents a node in a binary tree."""
    def __init__(self, val=0, left=None, right=None):
        """
        Initialize a TreeNode.

        Args:
            val (int, optional): The value of the node. Defaults to 0.
            left (TreeNode, optional): Left child node. Defaults to None.
            right (TreeNode, optional): Right child node. Defaults to None.
        """
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """Solution class for inverting a binary tree."""
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Invert a binary tree by swapping left and right children recursively.

        Args:
            root (Optional[TreeNode]): The root of the binary tree to invert.

        Returns:
            Optional[TreeNode]: The root of the inverted binary tree.
        """
        if root is None:
            return None

        tmp = root.left
        root.left = root.right
        root.right = tmp

        self.invertTree(root=root.left)
        self.invertTree(root=root.right)

        return root
