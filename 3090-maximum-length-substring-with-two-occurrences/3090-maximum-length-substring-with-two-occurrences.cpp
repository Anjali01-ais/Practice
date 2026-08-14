class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> fq(26, 0);

        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            // Add current character
            fq[s[r] - 'a']++;

            // If frequency exceeds 2, shrink window
            while (fq[s[r] - 'a'] > 2) {
                fq[s[l] - 'a']--;
                l++;
            }

            // Update maximum length
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};