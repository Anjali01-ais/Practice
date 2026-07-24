class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
    const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int len = 0; len < 3; len++) {
            for (int x = 0; x < MAXX; x++) {
                if (!dp[len][x]) continue;

                for (int v : nums) {
                    dp[len + 1][x ^ v] = true;
                }
            }
        }

        int ans = 0;
        for (bool ok : dp[3])
            if (ok) ans++;

        return ans;

    }
};