/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b,
                                struct ListNode* list2) {
    struct ListNode* a_iter = list1;
    struct ListNode* b_iter = list1;
    while (a != 1) {
        a_iter = a_iter->next;
        b_iter = b_iter->next;
        a--;
        b--;
    }
    while (b != -1) {
        b_iter = b_iter->next;
        b--;
    }
    a_iter->next = list2;
    while (list2->next != NULL) {
        list2 = list2->next;
    }
    list2->next = b_iter;
    return list1;
}