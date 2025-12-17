//  Approach (Brute Force/Basic Recursion)
// For every node, calculate the longest path that goes through it:
// Find the depth of its left subtree.
// Find the depth of its right subtree.
// The sum of these depths is the diameter passing through that node.
// Track the maximum diameter found during traversal
class Solution {
public:
 int maxDiameter = 0;
 //helper function
 int depth (TreeNode *node) {
    if (!node) return 0;
    int left = depth(node-> left);
    int right = depth (node->right);
 // update the maxium diamenter
  maxDiameter = max(maxDiameter , left+ right);
  return 1+ max(left,right);
 }
    int diameterOfBinaryTree(TreeNode* root) {
     depth (root);
     return maxDiameter;   
    }
};