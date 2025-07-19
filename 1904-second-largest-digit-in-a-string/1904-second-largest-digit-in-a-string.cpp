class Solution {
  public:
    int secondHighest(string s) {
        int first = -1;
        int second = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = s[i] - '0';
                if (num > first) {
                    second = first;
                    first = num;
                }
                else if (num < first && num > second) {
                    second = num;
                }
            }
        }
        return second;
    }

    int secondHighestWrapper(string s) {
        int result = secondHighest(s);
        return result;
    }
};

