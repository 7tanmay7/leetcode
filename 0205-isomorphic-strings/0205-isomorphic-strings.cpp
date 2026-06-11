class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char , char> mps;
      unordered_map<char , char>mpt;
      for(int i=0 ; i<s.size();i++){
           if (mps.find(s[i]) == mps.end() && mpt.find(t[i]) == mpt.end()) {
            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        } else if (mps[s[i]] != t[i] || mpt[t[i]] != s[i]) {
            return false;
        }
    }

    return true;
}
};