class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int , int>>>maxH;
        for(int i=0; i< points.size(); i++) {
            int dist = points[i][0] * points[i][0]+ points[i][1]* points[i][1];

            maxH.push({dist ,{ points[i][0] , points[i][1]}});

            if(maxH.size()>k){
                maxH.pop();
            }
        }
        vector<vector<int>>ans;
        while(maxH.size()>0){
            pair<int, int>p =maxH.top().second;
            ans.push_back({p.first, p.second});
            maxH.pop();
        }
        return ans;
    }
};