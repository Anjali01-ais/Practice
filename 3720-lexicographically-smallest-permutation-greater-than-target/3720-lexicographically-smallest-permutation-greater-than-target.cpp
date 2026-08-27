class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        
        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; i--) {

            vector<int> freq = cnt;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (freq[x] == 0) {
                    possible = false;
                    break;
                }

                freq[x]--;
            }

            if (!possible)
                continue;
            int x = target[i] - 'a';
            int bigger = -1;

            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            string ans;
            for (int j = 0; j < i; j++) {
                ans += target[j];
            }
            ans += char('a' + bigger);
            freq[bigger]--;
            for (int c = 0; c < 26; c++) {
                while (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};