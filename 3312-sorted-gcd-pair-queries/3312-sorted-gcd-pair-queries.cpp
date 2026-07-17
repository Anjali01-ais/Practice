class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
       int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> multipleCnt(mx + 1, 0);

        // Count numbers divisible by g
        for (int g = 1; g <= mx; g++) {
            for (int m = g; m <= mx; m += g)
                multipleCnt[g] += freq[m];
        }

        vector<long long> exact(mx + 1, 0);

        // Inclusion-Exclusion
        for (int g = mx; g >= 1; g--) {
            long long k = multipleCnt[g];
            exact[g] = k * (k - 1) / 2;

            for (int m = 2 * g; m <= mx; m += g)
                exact[g] -= exact[m];
        }

        // Prefix counts
        vector<long long> prefix(mx + 1, 0);

        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }   
    
};