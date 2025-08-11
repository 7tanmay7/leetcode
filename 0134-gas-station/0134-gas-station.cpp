class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGasDeficit = 0;   // Total gas minus total cost
        int currentTank = 0;       // Gas left in tank for current trip
        int startingStation = 0;   // Candidate for starting station

        for(int station = 0; station < gas.size(); ++station) {
            int gasGain = gas[station] - cost[station];
            totalGasDeficit += gasGain;
            currentTank += gasGain;

            // If tank goes negative, can't start from here or before
            if(currentTank < 0) {
                startingStation = station + 1;
                currentTank = 0; // Reset for the next candidate
            }
        }
        // If total gas is less than total cost, impossible to complete
        return totalGasDeficit < 0 ? -1 : startingStation;
    }
};