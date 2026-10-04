class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (mp.count(node)) {
            return mp[node];
        }
        
        Node* copy = new Node(node->val);
        mp[node] = copy;
        
        for (auto n : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(n));
        }
        
        return copy;
    }
};