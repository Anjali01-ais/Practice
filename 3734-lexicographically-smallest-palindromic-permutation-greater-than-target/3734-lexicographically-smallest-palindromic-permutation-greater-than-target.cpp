class Solution {
private:
    std::string result = "";

    bool dfs(int idx, bool isGreater, std::vector<int>& halfFreq, std::vector<char>& half, int mid, const std::string& target) {
        int n = target.length();
        if (idx == half.size()) {
            std::string sb = "";
            for (char c : half) {
                sb += c;
            }
            
            if (mid != -1) {
                sb += (char)(mid + 'a');
            }
            
            for (int i = half.size() - 1; i >= 0; i--) {
                sb += half[i];
            }

            if (sb > target) {
                result = sb;
                return true;
            }
            return false;
        }

        for (int i = 0; i < 26; i++) {
            if (halfFreq[i] > 0) {
                char c = (char)(i + 'a');
                
                if (!isGreater && c < target[idx]) {
                    continue;
                }

                halfFreq[i]--;
                half[idx] = c;
                
                if (dfs(idx + 1, isGreater || c > target[idx], halfFreq, half, mid, target)) {
                    return true;
                }
                
                halfFreq[i]++;
            }
        }
        return false;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        result = "";
        int n = s.length();
        std::vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int odd = 0;
        int mid = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odd++;
                mid = i;
            }
        }
        if (odd > 1) return "";

        std::vector<int> halfFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        std::vector<char> half(n / 2);
        if (dfs(0, false, halfFreq, half, mid, target)) {
            return result;
        }
        
        return "";
    }
};