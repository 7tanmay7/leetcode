class Solution {
    public:
    void dfs (TreeNode * root , int level , vector<long long > &levelSum) {
        if (!root) return;
        if (level == levelSum.size())
        levelSum.push_back(0);
        // add node value to its level
        levelSum[level] += root->val;
        // recursive call
        dfs (root->left , level+ 1 , levelSum);
        dfs (root-> right, level+1, levelSum);
    }
        int maxLevelSum (TreeNode* root) {
            vector<long long> levelSum;
            dfs(root , 0, levelSum);
            int maxLevel=0;
            for (int i=1; i< levelSum.size(); i++){
                if(levelSum [i]> levelSum [maxLevel])
                maxLevel =i;
            }
            return maxLevel +1;
        }
        
};