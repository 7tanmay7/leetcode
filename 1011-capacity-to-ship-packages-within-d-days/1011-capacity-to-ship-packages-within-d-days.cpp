class Solution {
public:

    int getDays(vector<int> & w , int cap){
        int d=1, load =0;
        for(int x: w){
            if(load + x> cap){
                d++;
                load=x;
            }else{
                load +=x;
            }
        }
        return d;
    }
   int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        int ans = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (getDays(weights, mid) <= days) {
                ans = mid;
                h = mid - 1; // Try for a smaller capacity
            } else {
                l = mid + 1; // Increase capacity
            }
        }
        return ans;
    }
};