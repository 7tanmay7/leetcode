class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node before the head to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;      // Points to last node before duplicates
        ListNode* current = head;    // Traverses the list

        while (current != nullptr) {
            // Check if current node is a start of duplicates
            if (current->next != nullptr && current->val == current->next->val) {
                // Skip all nodes with the same value
                while (current->next != nullptr && current->val == current->next->val) {
                    current = current->next;
                }
                // Remove all duplicates
                prev->next = current->next;
            } else {
                // No duplicate — move prev
                prev = prev->next;
            }
            current = current->next;
        }

        return dummy->next;
    }
};


