
class Solution {
public:
    int findPosition(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex]);
        int pos = findPosition(inorder, preorder[preIndex], inStart, inEnd);
        preIndex++;

        root->left = buildSubTree(preorder, inorder, inStart, pos - 1, preIndex);
        root->right = buildSubTree(preorder, inorder, pos + 1, inEnd, preIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return buildSubTree(preorder, inorder, 0, inorder.size() - 1, preIndex);
    }
};
