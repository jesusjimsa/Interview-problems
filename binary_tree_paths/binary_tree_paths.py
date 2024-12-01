"""
Given the `root` of a binary tree, return *all root-to-leaf paths **in any order***.

A leaf is a node with no children.

## Example 1

```
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
```

## Example 2:

```
Input: root = [1]
Output: ["1"]
```

## Constraints:

* The number of nodes in the tree is in the range `[1, 100]`
* `-100 <= Node.val <= 100`
"""

from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    """
    A class representing a node in a binary tree.

    Attributes:
        val (int): The value stored in the node.
        left (TreeNode, optional): The left child node.
        right (TreeNode, optional): The right child node.
    """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """
    A class providing methods to solve binary tree-related problems.
    """
    def helper(self, root: Optional[TreeNode], solution_list: Optional[list], current_path=""):
        """
        Recursively find all root-to-leaf paths in a binary tree.

        Args:
            root (Optional[TreeNode]): The current node being processed.
            solution_list (List[str]): List to store all root-to-leaf paths.
            current_path (str, optional): The current path from root to current node.
        """
        if root is None:
            return None

        ARROW = "->"

        current_path += str(root.val)

        if root.left is None and root.right is None:
            solution_list.append(current_path)
        else:
            current_path += ARROW
            self.helper(root=root.left, solution_list=solution_list, current_path=current_path)
            self.helper(root=root.right, solution_list=solution_list, current_path=current_path)

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        """
        Find all root-to-leaf paths in a binary tree.

        Args:
            root (Optional[TreeNode]): The root of the binary tree.

        Returns:
            List[str]: A list of all root-to-leaf paths.
        """
        if root is None:
            return []

        result_list = []

        self.helper(root=root, solution_list=result_list)

        return result_list
