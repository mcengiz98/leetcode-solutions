/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    if (!(head->next)) return NULL;

    struct ListNode* iter = head->next;

    int sum = 0;
    while (iter->val) {
        sum += iter->val;
        iter = iter->next;
    }
    
    head->val = sum;
    head->next = mergeNodes(iter);

    return head;
}