class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long sum = 0;
        int l = 0;
        long long cnt = 0;

        for(int r = 0; r < n; r++) {
            sum += nums[r];

            while(sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }

            cnt += r - l + 1;
        }

        return cnt;
    }
};