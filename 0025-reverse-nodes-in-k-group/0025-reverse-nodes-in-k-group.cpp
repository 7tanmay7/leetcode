class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        for (int i = 0; i + k <= nodes.size(); i += k) {
            reverse(nodes.begin() + i, nodes.begin() + i + k);
        }
        for (int i = 0; i + 1 < nodes.size(); ++i) {
            nodes[i]->next = nodes[i+1];
        }
        if (!nodes.empty()) nodes.back()->next = nullptr;
        return nodes.empty() ? nullptr : nodes[0];
    }
};