/*
You are given two linked-lists representing two non-negative integers. The digits are stored in reverse order and each
of their nodes contain a single digit. Add the two numbers and return it as a linked list.
egdfvxdsfrwgetgdf
Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int maxValue(int first, int second) {
    return first > second ? first : second;
}

struct ListNode * addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *solution;
    struct ListNode *solution_alt;
    struct ListNode *node_l1 = l1;
    struct ListNode *node_l2 = l2;
    int next_it_l1 = 1;
    int next_it_l2 = 1;
    int next_n = 0;
    int next_it_rest = 10;
    int next_it_div = 1;
    int first_number = 0;
    int second_number = 0;
    int solution_val = 0;
    int i = 0;
    int j = 0;
    int max = 0;

    while (node_l1) {
        first_number += node_l1->val * next_it_l1;
        next_it_l1 *= 10;
        node_l1 = node_l1->next;
        i++;
    }

    while (node_l2) {
        second_number += node_l2->val * next_it_l2;
        next_it_l2 *= 10;
        node_l2 = node_l2->next;
        j++;
    }

    solution_val = first_number + second_number;
    max = maxValue(i, j);

    next_n = solution_val % next_it_rest / next_it_div;

    solution = (struct ListNode *)malloc(sizeof(struct ListNode));
    solution->val = next_n;

    solution_alt = solution;

    for (i = 1; i < max; i++) {
        solution_alt->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        solution_alt = solution_alt->next;

        next_it_div *= 10;
        next_it_rest *= 10;
        next_n = solution_val % next_it_rest / next_it_div;

        solution_alt->val = next_n;
    }

    return solution;
}

int main(int argc, char **argv) {
    struct ListNode *l1, *l2, *solution;

    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;

    l2->val = 5;
    l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;

    solution = addTwoNumbers(l1, l2);

    while (solution) {
        printf("%d", solution->val);
        solution = solution->next;
    }

    printf("\n");
    return 0;
}
