class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>freq;
     int n= nums.size();
     for(int i=0; i<n;i++)
     freq[nums[i]]++;
     priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;

     for(auto&pr : freq)
     {
        pq.push({pr.second,pr.first});
        if(pq.size()>k)pq.pop();
     }   
     vector<int> ans;
     while(!pq.empty())
     {
        auto top = pq.top();
        pq.pop();

        ans.push_back(top.second);
     }
     return ans;

    }
};