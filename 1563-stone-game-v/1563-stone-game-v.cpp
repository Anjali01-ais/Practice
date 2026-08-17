#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int max_score = 0;
                for (int k = i; k < j; ++k) {
                    long long left_sum = pref[k + 1] - pref[i];
                    long long right_sum = pref[j + 1] - pref[k + 1];

                    if (left_sum < right_sum) {
                        max_score = max(max_score, (int)left_sum + dp[i][k]);
                    } else if (left_sum > right_sum) {
                        max_score = max(max_score, (int)right_sum + dp[k + 1][j]);
                    } else {
                        max_score = max(max_score, (int)left_sum + max(dp[i][k], dp[k + 1][j]));
                    }
                }
                dp[i][j] = max_score;
            }
        }

        return dp[0][n - 1];
    }
};