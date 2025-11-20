/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;

        // Pointer to traverse the list
        ListNode* temp = head;

        // Traverse and push values into vector
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the vector
        sort(arr.begin(), arr.end());

        // Reassign sorted values to list nodes
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }

        // Return head of sorted list
        return head;
    }
};
