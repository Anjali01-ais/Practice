class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         int n = asteroids.size();
        vector<int> st;

        for (int i = 0; i < n; i++) {
            bool dead = false;

            while (!st.empty() && st.back() > 0 && asteroids[i] < 0) {

                if (abs(st.back()) < abs(asteroids[i])) {
                    st.pop_back();
                    continue;
                }
                else if (abs(st.back()) == abs(asteroids[i])) {
                    st.pop_back();
                }

                dead = true;
                break;
            }

            if (!dead) {
                st.push_back(asteroids[i]);
            }
        }

        return st;
    }
};