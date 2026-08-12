class Solution {
public:

    int solve(string& s, int left, int right, int k) {

        // Empty substring
        if (left > right)
            return 0;

        // If k = 1, every character is valid
        if (k == 1)
            return right - left + 1;

        // Frequency of characters
        vector<int> freq(26, 0);

        for (int i = left; i <= right; i++) {
            freq[s[i] - 'a']++;
        }

        // Find a character whose frequency is less than k
        for (int i = left; i <= right; i++) {

            if (freq[s[i] - 'a'] < k) {

                // Split around this invalid character
                int leftAns = solve(s, left, i - 1, k);
                int rightAns = solve(s, i + 1, right, k);

                return max(leftAns, rightAns);
            }
        }

        // Every character occurs at least k times
        return right - left + 1;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
};
