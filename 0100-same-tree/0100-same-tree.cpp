class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both nodes are null
        if (p == nullptr && q == nullptr)
            return true;
        
        // If one of the nodes is null, but the other isn't
        if (p == nullptr || q == nullptr)
            return false;
        
        // If values are not equal
        if (p->val != q->val)
            return false;
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};