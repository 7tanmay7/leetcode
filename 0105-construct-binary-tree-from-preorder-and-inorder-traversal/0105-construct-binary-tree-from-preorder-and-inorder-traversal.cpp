
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
// optimised approach (using maps)
// class Solution {
// public:
//     unordered_map<int, int> inMap;

//     TreeNode* buildSubTree(vector<int>& preorder, int inStart, int inEnd, int& preIndex) {
//         if (inStart > inEnd)
//             return nullptr;

//         int rootVal = preorder[preIndex++];
//         TreeNode* root = new TreeNode(rootVal);
//         int pos = inMap[rootVal];

//         root->left = buildSubTree(preorder, inStart, pos - 1, preIndex);
//         root->right = buildSubTree(preorder, pos + 1, inEnd, preIndex);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         inMap.clear();
//         for (int i = 0; i < inorder.size(); i++) {
//             inMap[inorder[i]] = i;
//         }

//         int preIndex = 0;
//         return buildSubTree(preorder, 0, inorder.size() - 1, preIndex);
//     }
// };
