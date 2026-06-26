#include <vector>
#include <queue>

using namespace std;

class Solution {
    struct Node {
        int val;
        ListNode* currNode;
        Node(int v, ListNode* node) : val(v), currNode(node) {}
    };

    struct Compare {
        bool operator()(const Node& a, const Node& b) {
            return a.val > b.val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node, vector<Node>, Compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(Node(lists[i]->val, lists[i]));
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            Node topNode = pq.top();
            pq.pop();

            ListNode* curr = topNode.currNode;
            tail->next = curr;
            tail = tail->next;

            if (curr->next != nullptr) {
                pq.push(Node(curr->next->val, curr->next));
            }
        }

        return dummy->next;
    }
};