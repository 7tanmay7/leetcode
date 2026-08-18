class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m = station.length();

        if(n<=1) 
        return 0;

        vector<int> earliest(n);

        int j=0;
        for(int i =0; i<n; ++i){
            while( j< m && station[j] != skill[i]){
                j++;
            }
            earliest[i] =j;
            j++;
        }
        vector<int> latest(n);
        j = m-1;
        for( int i= n-1 ; i>=0;i--){
            while(j >= 0 && station[j]!= skill[i]){
                j--;
            }
            latest[i]=j;
            j--;
        }
        int maxGap =0;
        for(int i=1 ; i<n ; ++i){
            maxGap = max(maxGap, latest[i] - earliest[i - 1]);
        }
        return maxGap;
    }
};
