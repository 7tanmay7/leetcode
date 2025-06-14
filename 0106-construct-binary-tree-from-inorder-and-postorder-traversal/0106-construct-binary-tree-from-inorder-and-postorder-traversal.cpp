class Solution {
public:
    int findPosition(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex]);
        int pos = findPosition(inorder, postorder[postIndex], inStart, inEnd);
        postIndex--;

        // Right first (since postorder is Left → Right → Root)
        root->right = buildSubTree(inorder, postorder, pos + 1, inEnd, postIndex);
        root->left = buildSubTree(inorder, postorder, inStart, pos - 1, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        return buildSubTree(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
};
