class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int a : asteroids) {
            bool exploded = false;
            // Handle left-moving asteroid collision
            while (!stack.empty() && a < 0 && stack.back() > 0) {
                if (stack.back() < -a) {
                    stack.pop_back();
                    continue; // Check for more collisions
                } else if (stack.back() == -a) {
                    stack.pop_back();
                    exploded = true;
                    break; // Both explode
                } else {
                    exploded = true;
                    break; // Current asteroid explodes
                }
            }
            if (!exploded) {
                stack.push_back(a);
            }
        }
        return stack;
    }
};