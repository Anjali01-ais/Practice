class Solution {
public:
    string smallestPalindrome(string s, int k) {
       int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }

        string mid_char = "";
        int counts[26] = {0};
        int N = 0;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid_char = string(1, i + 'a');
            }
            counts[i] = freq[i] / 2;
            N += counts[i];
        }

        vector<pair<int, int>> factors[5005];
        for (int i = 2; i <= N; ++i) {
            int temp = i;
            for (int p = 2; p * p <= temp; ++p) {
                if (temp % p == 0) {
                    int cnt = 0;
                    while (temp % p == 0) {
                        cnt++;
                        temp /= p;
                    }
                    factors[i].push_back({p, cnt});
                }
            }
            if (temp > 1) {
                factors[i].push_back({temp, 1});
            }
        }

        vector<int> primes;
        bool is_p[5005];
        fill(is_p, is_p + 5005, true);
        for (int i = 2; i <= N; ++i) {
            if (is_p[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= N; j += i) {
                    is_p[j] = false;
                }
            }
        }

        int pcount[5005] = {0};

        auto apply_factors = [&](int val, int sign) {
            if (val <= 1) return;
            for (auto& f : factors[val]) {
                pcount[f.first] += sign * f.second;
            }
        };

        for (int i = 2; i <= N; ++i) apply_factors(i, 1);
        for (int i = 0; i < 26; ++i) {
            for (int j = 2; j <= counts[i]; ++j) {
                apply_factors(j, -1);
            }
        }

        long long CAP = 100000000000LL;
        long long initial_T = 1;

        for (int p : primes) {
            if (pcount[p] > 0) {
                int cnt = pcount[p];
                while (cnt--) {
                    if (CAP / p < initial_T) {
                        initial_T = CAP;
                        break;
                    }
                    initial_T *= p;
                }
            }
            if (initial_T == CAP) break;
        }

        if (k > initial_T) return "";

        string ans = "";
        int current_N = N;

        for (int step = 0; step < N; ++step) {
            for (int c = 0; c < 26; ++c) {
                if (counts[c] > 0) {
                    apply_factors(counts[c], 1);
                    apply_factors(current_N, -1);

                    long long branch_T = 1;
                    for (int p : primes) {
                        if (pcount[p] > 0) {
                            int cnt = pcount[p];
                            while (cnt--) {
                                if (CAP / p < branch_T) {
                                    branch_T = CAP;
                                    break;
                                }
                                branch_T *= p;
                            }
                        }
                        if (branch_T == CAP) break;
                    }

                    apply_factors(counts[c], -1);
                    apply_factors(current_N, 1);

                    if (k <= branch_T) {
                        ans += (char)('a' + c);
                        apply_factors(counts[c], 1);
                        apply_factors(current_N, -1);
                        counts[c]--;
                        current_N--;
                        break;
                    } else {
                        k -= branch_T;
                    }
                }
            }
        }

        string rev_ans = ans;
        reverse(rev_ans.begin(), rev_ans.end());
        return ans + mid_char + rev_ans; 
    }
};