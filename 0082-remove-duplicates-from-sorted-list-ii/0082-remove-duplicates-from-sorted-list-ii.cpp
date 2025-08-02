class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node before head to handle edge case where head itself is duplicate
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;

        while (temp->next != nullptr && temp->next->next != nullptr) {
            // If next two nodes have same value — duplicate found
            if (temp->next->val == temp->next->next->val) {
                int dupVal = temp->next->val;
                // Skip all nodes with that value
                while (temp->next != nullptr && temp->next->val == dupVal) {
                    temp->next = temp->next->next;
                }
            } else {
                // No duplicate, move ahead
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};

