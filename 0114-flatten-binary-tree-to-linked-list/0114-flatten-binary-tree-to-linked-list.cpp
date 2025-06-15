
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (!root->left) {
                root = root->right;
            } else {
                TreeNode* curr = root->left;

                // Find the rightmost node of the left subtree
                while (curr->right) {
                    curr = curr->right;
                }

                // Connect it to the root's right subtree
                curr->right = root->right;

                // Move left subtree to right and nullify left
                root->right = root->left;
                root->left = nullptr;

                // Move to next right node
                root = root->right;
            }
        }
    }
};
