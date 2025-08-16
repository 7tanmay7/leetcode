class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num); // Convert number to string for easy digit change
        for(char &c : s) {
            if(c == '6') {         // Find the first '6'
                c = '9';           // Change it to '9'
                break;             // Only change once
            }
        }
        return stoi(s);            // Convert back to integer
    }
};