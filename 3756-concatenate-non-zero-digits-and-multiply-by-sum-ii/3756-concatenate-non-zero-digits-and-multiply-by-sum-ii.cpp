class Solution {
public:
     static const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
     
        vector<int> pos;
        vector<long long> prefValue;
        vector<long long> prefDigit;

        int n = s.size();

        vector<long long> pow10(n + 2, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        long long val = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                int d = s[i] - '0';
                pos.push_back(i);

                val = (val * 10 + d) % MOD;
                sum += d;

                prefValue.push_back(val);
                prefDigit.push_back(sum);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long x = prefValue[R];

            if (L > 0) {
                x = (x - prefValue[L - 1] * pow10[R - L + 1]) % MOD;
                if (x < 0) x += MOD;
            }

            long long digitSum = prefDigit[R];
            if (L > 0)
                digitSum -= prefDigit[L - 1];

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;   
    }
};