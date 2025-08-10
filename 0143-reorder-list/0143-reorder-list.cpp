class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // Step 1: Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next; fast = fast->next->next;
        }
        // Step 2: Reverse second half
        ListNode *prev = nullptr, *curr = slow->next;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow->next = nullptr;
        // Step 3: Merge
        ListNode *first = head, *second = prev;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};