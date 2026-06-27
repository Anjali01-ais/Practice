class Solution {
public:
    int maximumLength(vector<int>& nums) {
       unordered_map<long long, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int ans = 1;

        if (freq.count(1)) {
            int count1 = freq[1];
            if (count1 % 2 == 0) count1--;
            ans = max(ans, count1);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                auto it = freq.find(cur);
                if (it == freq.end() || it->second < 2) {
                    break;
                }

                len += 2;
                
                if (cur > 1000000000LL / cur) {
                    len--; 
                    cur = -1;
                    break;
                }
                cur = cur * cur;
            }

            if (cur != -1) {
                auto it = freq.find(cur);
                if (it != freq.end() && it->second >= 1) {
                    len++;
                } else {
                    len--;
                }
            }

            ans = max(ans, len);
        }

        return ans;
    }
};