class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort (g.begin(), g.end());
        sort(s.begin(), s.end());
        int child =0;
        for(int i=0; i<s.size()&& child<g.size();i++){
            if(s[i]>= g[child]){
                child++;
            }
            }
            return child;
        }
};