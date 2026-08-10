class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; i++) {
            // Try removing every perfect square <= i
            for (int k = 1; k * k <= i; k++) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; 
                }
            }
        }
        
        return dp[n];
    }
};;