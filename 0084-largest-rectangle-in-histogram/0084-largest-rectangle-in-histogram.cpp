class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     int n=(int)heights.size();
     vector<int> leftmin(n);
        stack<int> st;

        // Nearest smaller to left
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) leftmin[i] = 0;
            else leftmin[i] = st.top() + 1;

            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        vector<int> rightmin(n);

        // Nearest smaller to right
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) rightmin[i] = n - 1;
            else rightmin[i] = st.top() - 1;

            st.push(i);
        }

        int maxA = 0;

        for(int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightmin[i] - leftmin[i] + 1));
        }

        return maxA;
    }
};