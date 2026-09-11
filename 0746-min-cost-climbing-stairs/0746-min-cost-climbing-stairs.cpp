class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& cost, int i) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take1 = solve(cost, i + 1);
        int take2 = solve(cost, i + 2);

        return dp[i] = cost[i] + min(take1, take2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.assign(n, -1);

        return min(solve(cost, 0), solve(cost, 1));
        
    }
};