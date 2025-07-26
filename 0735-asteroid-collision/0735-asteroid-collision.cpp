class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // Handle collisions when current is left-moving and top is right-moving
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > st.top()) {
                    st.pop(); // destroy top and continue loop
                } 
                else if (abs(a) == st.top()) {
                    st.pop(); // both explode
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true; // left-moving is smaller, destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector (in reverse)
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};
