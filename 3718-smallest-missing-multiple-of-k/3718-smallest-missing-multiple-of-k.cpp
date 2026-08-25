class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int x : nums) {
            mp[x]++;
        }

        int x = k;

        while(mp.find(x) != mp.end()) {
            x += k;
        }

        return x;
    }
};