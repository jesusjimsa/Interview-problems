"""
Given the `root` of a binary tree, return the same tree where every subtree (of the given tree) not containing a `1` has
been removed.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

## Example 1

```
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

## Example 2

```
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

## Example 3

```
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

## Constraints:

* The number of nodes in the tree is in the range `[1, 200]`.
* `Node.val` is either `0` or `1`.
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
    A class providing methods to solve binary tree pruning problems.
    """
    def sumBranch(self, root: Optional[TreeNode], total=0) -> int:
        """
        Calculate the sum of values in a branch of the binary tree.

        Args:
            root (Optional[TreeNode]): The current node being processed.
            total (int, optional): Cumulative sum of branch values. Defaults to 0.

        Returns:
            int: Sum of values in the branch.
        """
        if root is None:
            return 0

        total += root.val

        total_left = self.sumBranch(root=root.left, total=total)
        total_right = self.sumBranch(root=root.right, total=total)

        return total + total_left + total_right

    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Prune the binary tree by removing branches with zero sum.

        Args:
            root (Optional[TreeNode]): The root of the binary tree.

        Returns:
            Optional[TreeNode]: The pruned tree or None if the entire tree is pruned.
        """
        if root is None:
            return None


        if self.sumBranch(root=root.left) == 0:
            root.left = None

        if self.sumBranch(root=root.right) == 0:
            root.right = None

        self.pruneTree(root=root.left)
        self.pruneTree(root=root.right)

        if root.val == 0 and root.left is None and root.right is None:
            return None

        return root
