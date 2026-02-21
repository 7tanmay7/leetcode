class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0,n=s.size();

        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            int start=i;
            while(i<n && s[i]!=' ') i++;
            string temp=s.substr(start,i-start);
            reverse(temp.begin(),temp.end());
            if(!ans.empty()) ans.push_back(' ');
            ans+=temp;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};