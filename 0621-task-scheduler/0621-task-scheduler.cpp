class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26,0);
    for(char task: tasks){
        freq[task-'A']++;
    }
    priority_queue<int> pq;
    for( int count : freq){
        if(count >0){
            pq.push(count);
        }
    }
    int totalTime =0;

    while(!pq.empty()){
        vector<int> remain;
        int cycle = n+1;
        int taskCount =0;

        while(cycle>0 && !pq.empty()){
            int currentFreq =pq.top();
            pq.pop();

            if(currentFreq > 1){
                remain.push_back(currentFreq -1);
            }
            cycle--;
            taskCount++;
        }
        for(int count : remain){
            pq.push(count);
        }
        if(pq.empty()){
            totalTime +=taskCount;
        }else {
            totalTime +=(n+1);
        }
    }
     return totalTime;
    }
};