class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int n = nums.size();
        stack<int> st;
        int second = INT_MIN; // candidate for nums[k]

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < second) {
                return true;
            }

            while (!st.empty() && st.top() < nums[i]) {
                second = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;

    }
};