/**
 * @brief You are given two **non-empty** linked lists representing two non-negative integers. The most significant
 * digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.


    #### Example 1:

    ```
    Input: l1 = [7,2,4,3], l2 = [5,6,4]
    Output: [7,8,0,7]
    ```

    #### Example 2:

    ```
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [8,0,7]
    ```

    #### Example 3:

    ```
    Input: l1 = [0], l2 = [0]
    Output: [0]
    ```

    ### Constraints:

    * The number of nodes in each linked list is in the range `[1, 100]`.
    * `0 <= Node.val <= 9`
    * It is guaranteed that the list represents a number that does not have leading zeros.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

#define true    1 == 1
#define false   !(true)

struct ListNode {
    int val;
    struct ListNode *next;
};

int listSize(struct ListNode* l1) {
    int size = 1;   // "You are given two non-empty"
    struct ListNode* copy_node = l1->next;

    while (copy_node != NULL) {
        size++;
        copy_node = copy_node->next;
    }

    return size;
}

int getIndex(int index, struct ListNode* l1, int list_size) {
    struct ListNode* copy_node;

    if (index > list_size || index < 0) {
        return -1;
    }

    copy_node = malloc(sizeof(struct ListNode));
    copy_node->val = l1->val;
    copy_node->next = l1->next;

    for (int i = 0; i < index; i++) {
        copy_node = copy_node->next;
    }

    return copy_node->val;
}

int maxValue(int first, int second) {
    return first > second ? first : second;
}

void reverse(struct ListNode** head_ref) {
    struct ListNode* prev = NULL;
    struct ListNode* current = *head_ref;
    struct ListNode* next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int size_l1 = listSize(l1);
    int size_l2 = listSize(l2);
    int size_l1_aux = size_l1;
    int size_l2_aux = size_l2;
    int max_size = maxValue(size_l1, size_l2);
    int elem_l1, elem_l2;
    int tmp_sum, above_ten;
    struct ListNode* reverse_solution = malloc(sizeof(struct ListNode));
    struct ListNode* reverse_first_node = reverse_solution;

    above_ten = false;

    for (int i = 0; i < max_size; i++) {
        elem_l1 = getIndex(size_l1_aux - i - 1, l1, size_l1);
        elem_l2 = getIndex(size_l2_aux - i - 1, l2, size_l2);

        if (elem_l1 != -1 && elem_l2 != -1) {
            tmp_sum = elem_l1 + elem_l2;

            tmp_sum = above_ten ? tmp_sum + 1 : tmp_sum;
            above_ten = false;

            if (tmp_sum >= 10) {
                above_ten = true;
                tmp_sum = tmp_sum % 10;
            }

            reverse_solution->val = tmp_sum;
        }
        else if (elem_l1 == -1 && elem_l2 >= 0) {
            tmp_sum = elem_l2;
            tmp_sum = above_ten ? tmp_sum + 1 : tmp_sum;
            above_ten = false;

            if (tmp_sum >= 10) {
                above_ten = true;
                tmp_sum = tmp_sum % 10;
            }
            
            reverse_solution->val = tmp_sum;
        }
        else if (elem_l1 >= 0 && elem_l2 == -1) {
            tmp_sum = elem_l1;
            tmp_sum = above_ten ? tmp_sum + 1 : tmp_sum;
            above_ten = false;

            if (tmp_sum >= 10) {
                above_ten = true;
                tmp_sum = tmp_sum % 10;
            }
            reverse_solution->val = tmp_sum;
        }

        if (i + 1 < max_size) {
            reverse_solution->next = malloc(sizeof(struct ListNode));
            reverse_solution = reverse_solution->next;
        }
    }

    reverse(&reverse_first_node);

    return reverse_first_node;
}

void printList(struct ListNode* head) {
    struct ListNode* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

int main(int argc, char *argv[]) {
    struct ListNode* l1;
    struct ListNode* l2;

    l1 = malloc(sizeof(struct ListNode));
    l1->val = 7;
    l1->next = malloc(sizeof(struct ListNode));
    l1->next->val = 2;
    l1->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->val = 4;
    l1->next->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->next->val = 3;

    l2 = malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;

    printf("l1 - %d\n", listSize(l1));
    printf("l2 - %d\n", listSize(l2));

    int size_l1 = listSize(l1);
    printf("Idx 2 - %d\n", getIndex(2, l1, size_l1));

    printList(l1);
    printf("\n");
    printList(l2);
    printf("\n");
    printList(addTwoNumbers(l1, l2));
    printf("\n");
}
