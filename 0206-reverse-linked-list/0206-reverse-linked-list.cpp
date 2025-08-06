class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        stack<ListNode*> st;
        ListNode* temp = head;

        // Push all nodes to the stack
        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }

        // Pop from stack to rebuild reversed list
        ListNode* newHead = st.top();
        st.pop();
        temp = newHead;

        while (!st.empty()) {
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }

        temp->next = NULL; // Mark the new tail
        return newHead;
    }
};
