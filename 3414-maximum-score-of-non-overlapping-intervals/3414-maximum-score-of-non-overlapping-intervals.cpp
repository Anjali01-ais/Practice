class Solution {
public:

    struct Node {
        long long score;
        vector<int> indices;
    };

    int n;
    bool better(const Node& a, const Node& b) {

        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<vector<Node>> dp;
    vector<vector<bool>> vis;

    Node solve(int i, int k, vector<vector<int>>& intervals) {
        if (i == n || k == 0) {
            return {0, {}};
        }

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        Node skip = solve(i + 1, k, intervals);

        int right = intervals[i][1];
        int lo = i + 1;
        int hi = n;

        while (lo < hi) {

            int mid = lo + (hi - lo) / 2;

            if (intervals[mid][0] > right)
                hi = mid;
            else
                lo = mid + 1;
        }

        int next = lo;

        Node take = solve(next, k - 1, intervals);

        take.score += intervals[i][2];

        take.indices.push_back(intervals[i][3]);
        sort(take.indices.begin(), take.indices.end());

        Node ans;

        if (better(take, skip))
            ans = take;
        else
            ans = skip;

        return dp[i][k] = ans;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {

                 if (a[0] != b[0])
                     return a[0] < b[0];

                 return a[1] < b[1];
             });

        dp.assign(n, vector<Node>(5));
        vis.assign(n, vector<bool>(5, false));

        return solve(0, 4, intervals).indices;
    }
};