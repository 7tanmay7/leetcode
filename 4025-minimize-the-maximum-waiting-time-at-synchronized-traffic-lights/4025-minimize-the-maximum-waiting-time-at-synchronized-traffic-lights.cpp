class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int m =0, ans =0;
        for (int l: lights) m = max(m , l);

        for(int t : arrivalTime){
            int r = t % period;
    if (r >= m) ans = max(ans, period - r);
        }
        
        return ans;
    }
};