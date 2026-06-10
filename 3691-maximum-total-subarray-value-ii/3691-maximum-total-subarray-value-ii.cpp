class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return 0;

        int LOG = log2(n) + 1;
        vector<vector<int>> st_max(n, vector<int>(LOG));
        vector<vector<int>> st_min(n, vector<int>(LOG));

        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }

        vector<int> log_table(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }

        auto getValue = [&](int L, int R) {
            int j = log_table[R - L + 1];
            int maximum = max(st_max[L][j], st_max[R - (1 << j) + 1][j]);
            int minimum = min(st_min[L][j], st_min[R - (1 << j) + 1][j]);
            return maximum - minimum;
        };

        // pair<value, pair<L, R>>
        priority_queue<pair<int, pair<int, int>>> pq;
        unordered_set<long long> visited;

        pq.push({getValue(0, n - 1), {0, n - 1}});
        visited.insert(((long long)0 << 32) | (n - 1));

        long long total_value = 0;

        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();

            int val = top.first;
            int L = top.second.first;
            int R = top.second.second;

            total_value += val;

            if (L < R) {
                long long key1 = ((long long)(L + 1) << 32) | R;
                if (visited.find(key1) == visited.end()) {
                    visited.insert(key1);
                    pq.push({getValue(L + 1, R), {L + 1, R}});
                }

                long long key2 = ((long long)L << 32) | (R - 1);
                if (visited.find(key2) == visited.end()) {
                    visited.insert(key2);
                    pq.push({getValue(L, R - 1), {L, R - 1}});
                }
            }
        }

        return total_value;
    }
};