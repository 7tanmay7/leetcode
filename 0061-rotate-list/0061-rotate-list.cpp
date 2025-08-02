class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length of the list and get the tail node
        int len = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            len++;
            tail = tail->next;
        }

        // Step 2: Modulo k to avoid full-length unnecessary rotations
        k = k % len;
        if (k == 0) return head;

        // Step 3: Make it a circular list
        tail->next = head;

        // Step 4: Find the new tail (len - k steps from beginning)
        ListNode* newTail = head;
        for (int i = 1; i < len - k; ++i) {
            newTail = newTail->next;
        }

        // Step 5: The new head is next of newTail
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
