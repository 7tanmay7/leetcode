class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // Loop through all 32 possible bit positions of an integer
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            
            // Count how many numbers have a '1' at the i-th bit position
            for (int num : nums) {
                bitSum += (num >> i) & 1;
            }
            
            // If the count isn't a multiple of 3, this bit belongs to our unique number
            if (bitSum % 3 != 0) {
                result |= (1 << i); // Left shift '1' to its proper place and add it to result
            }
        }
        
        return result;
    }
};