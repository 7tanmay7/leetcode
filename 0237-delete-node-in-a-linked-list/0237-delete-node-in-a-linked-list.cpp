/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Since we can't access the node before this one, 
        // we copy the value of the next node into the current node.
        node->val = node->next->val;
        
        // Then we point the current node to the one after the next,
        // effectively "deleting" the next node from the sequence.
        node->next = node->next->next;
    }
};