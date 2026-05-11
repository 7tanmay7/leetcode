class Solution {
public:
    int characterReplacement(string s, int k) {
        int high =0; int low =0; int n = s.size(); int max_cnt =0; int f[256]={0}; int res=0;

        for(int high =0; high<n; high++){
            f[s[high]]++;
        max_cnt = max(max_cnt, f[s[high]]);
            while((high - low + 1) - max_cnt > k){
                f[s[low]]--;
                low++;
            }
            res = max(res , high-low+1);
        }
        return res;
        
    }
};