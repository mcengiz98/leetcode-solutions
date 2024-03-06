/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
    if (!head || !(head->next)) return false;

    struct ListNode* fast = head->next;
    struct ListNode* slow = head;

    while (fast != slow) {
        if (!fast || !(fast->next)) return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}