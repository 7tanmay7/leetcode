/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode node, int currentSum) {
        // Base case: if the node is null, return 0
        if (node == null) {
            return 0;
        }

        // Update the current path sum: 
        // Shift previous digits left (multiply by 10) and add current value
        currentSum = currentSum * 10 + node.val;

        // If we reach a leaf node, return the accumulated sum for this path
        if (node.left == null && node.right == null) {
            return currentSum;
        }

        // Recursively calculate the sum for left and right subtrees
        return dfs(node.left, currentSum) + dfs(node.right, currentSum);
    }
}