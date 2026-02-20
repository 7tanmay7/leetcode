/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
          node->val = node->next->val;       // Copy next node's value to current node
        ListNode* temp = node->next;       // Store next node
        node->next = node->next->next;     // Bypass next node
        delete temp;  
        
    }
};