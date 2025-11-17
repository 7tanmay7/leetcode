

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // No cycle if list is empty or has only one node
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if there's a cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected
                break;
            }
        }

        // No cycle detected
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Step 2: Find the starting node of the cycle
        slow = head; // Reset slow to head
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Start of cycle
    }
};
