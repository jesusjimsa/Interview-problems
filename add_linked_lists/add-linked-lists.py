'''
You are given two linked-lists representing two non-negative integers. The digits are stored in reverse order and each
of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
'''


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2, c=0):
        solution = ListNode(0)
        solution_next = solution
        node_l1 = l1
        node_l2 = l2
        next_it_l1 = 1
        next_it_l2 = 1
        next_n = 0
        next_it_rest = 10
        next_it_div = 1
        first_number = 0
        second_number = 0
        solution_val = 0

        while node_l1:
            first_number += node_l1.val * next_it_l1
            next_it_l1 *= 10
            node_l1 = node_l1.next

        while node_l2:
            second_number += node_l2.val * next_it_l2
            next_it_l2 *= 10
            node_l2 = node_l2.next

        solution_val = first_number + second_number

        next_n = int(solution_val % next_it_rest / next_it_div)

        solution = ListNode(next_n)
        solution_next = solution

        for _ in range(1, len(str(solution_val))):
            next_it_div *= 10
            next_it_rest *= 10
            next_n = int(solution_val % next_it_rest / next_it_div)
            solution_next.next = ListNode(next_n)
            solution_next = solution_next.next

        # Fill this in.
        return solution


l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

result = Solution().addTwoNumbers(l1, l2)
while result:
    print(result.val)
    result = result.next
# 7 0 8
