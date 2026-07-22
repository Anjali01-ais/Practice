class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
       int n = s.length();
        
        // Prefix sum to compute total '1's in the entire string 's'
        vector<int> pref1(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref1[i + 1] = pref1[i] + (s[i] == '1' ? 1 : 0);
        }
        int total_ones = pref1[n]; // Total '1's in the entire string

        // Compress the string into alternating continuous blocks
        vector<char> type;
        vector<int> len;
        vector<int> b_start;
        vector<int> b_end;
        vector<int> pos(n);

        int i = 0, m = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            type.push_back(s[i]);
            len.push_back(j - i);
            b_start.push_back(i);
            b_end.push_back(j - 1);
            for (int k = i; k < j; k++) pos[k] = m;
            m++;
            i = j;
        }

        // Setup arrays to build Sparse Tables
        vector<int> len0(m, 0);
        vector<int> len1(m, 1e9);
        vector<int> sum0_adj(m, -1e9);

        for (int k = 0; k < m; k++) {
            if (type[k] == '0') {
                len0[k] = len[k];
            } else {
                len1[k] = len[k];
                int L0 = (k > 0 && type[k - 1] == '0') ? len[k - 1] : 0;
                int R0 = (k < m - 1 && type[k + 1] == '0') ? len[k + 1] : 0;
                sum0_adj[k] = L0 + R0;
            }
        }

        // Build Sparse Tables for O(1) Range Maximum / Minimum Queries
        int K = 20;
        vector<int> log2_arr(m + 1, 0);
        for (int k = 2; k <= m; k++) log2_arr[k] = log2_arr[k / 2] + 1;

        vector<vector<int>> st_max0(m, vector<int>(K, 0));
        vector<vector<int>> st_min1(m, vector<int>(K, 1e9));
        vector<vector<int>> st_max_adj(m, vector<int>(K, -1e9));

        for (int k = 0; k < m; k++) {
            st_max0[k][0] = len0[k];
            st_min1[k][0] = len1[k];
            st_max_adj[k][0] = sum0_adj[k];
        }

        for (int j = 1; j < K; j++) {
            for (int k = 0; k + (1 << j) <= m; k++) {
                st_max0[k][j] = max(st_max0[k][j - 1], st_max0[k + (1 << (j - 1))][j - 1]);
                st_min1[k][j] = min(st_min1[k][j - 1], st_min1[k + (1 << (j - 1))][j - 1]);
                st_max_adj[k][j] = max(st_max_adj[k][j - 1], st_max_adj[k + (1 << (j - 1))][j - 1]);
            }
        }

        auto get_max0 = [&](int L, int R) {
            if (L > R) return 0;
            int j = log2_arr[R - L + 1];
            return max(st_max0[L][j], st_max0[R - (1 << j) + 1][j]);
        };
        auto get_min1 = [&](int L, int R) {
            if (L > R) return (int)1e9;
            int j = log2_arr[R - L + 1];
            return min(st_min1[L][j], st_min1[R - (1 << j) + 1][j]);
        };
        auto get_max_adj = [&](int L, int R) {
            if (L > R) return (int)-1e9;
            int j = log2_arr[R - L + 1];
            return max(st_max_adj[L][j], st_max_adj[R - (1 << j) + 1][j]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int bL = pos[l];
            int bR = pos[r];

            // Substring occupies a single uniform block - no internal bounds -> no trade possible
            if (bL == bR) {
                ans.push_back(total_ones);
                continue;
            }

            // Slice boundaries mapping to query indices
            int LL = b_end[bL] - l + 1;
            int LR = r - b_start[bR] + 1;

            int iL = bL + 1;
            int iR = bR - 1;

            // Only 2 adjacent blocks inside query range, no strictly internal '1' blocks available to trade
            if (iL > iR) {
                ans.push_back(total_ones);
                continue;
            }

            // Find longest possible 0-block internally vs boundaries
            int max_0 = get_max0(iL, iR);
            if (type[bL] == '0') max_0 = max(max_0, LL);
            if (type[bR] == '0') max_0 = max(max_0, LR);

            // Find shortest possible internal 1-block to drop
            int min_1 = get_min1(iL, iR);
            
            // If no interior '1' blocks are available, a trade is impossible
            if (min_1 >= 1e9) { 
                ans.push_back(total_ones);
                continue;
            }

            // Analyze net profit if flipping a merged 0-block directly adjacent to our removed 1-block
            int max_adj = -1e9;

            // Scenario 1: The left-most internal valid 1-block
            if (type[iL] == '1') {
                int left_val = (type[bL] == '0') ? LL : 0;
                int right_val = (iL == iR) ? ((type[bR] == '0') ? LR : 0) : len0[iL + 1];
                max_adj = max(max_adj, left_val + right_val);
            }

            // Scenario 2: The right-most internal valid 1-block
            if (iL < iR && type[iR] == '1') {
                int left_val = len0[iR - 1];
                int right_val = (type[bR] == '0') ? LR : 0;
                max_adj = max(max_adj, left_val + right_val);
            }

            // Scenario 3: Check all interior blocks heavily nested away from query boundary trims
            if (iL + 1 <= iR - 1) {
                max_adj = max(max_adj, get_max_adj(iL + 1, iR - 1));
            }

            // Net optimal gain is the best result of merging blocks locally OR flipping a disjoint maximum 0-block
            int gain = max(max_adj, max_0 - min_1);
            
            // Gain can be negative if trade destroys more 1s than it restores (in which case we perform 0 trades)
            ans.push_back(total_ones + max(0, gain));
        }

        return ans;
    }
};