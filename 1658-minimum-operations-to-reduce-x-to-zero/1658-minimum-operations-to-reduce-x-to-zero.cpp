class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums) totalSum += num;

        int target = totalSum - x;
        if(target < 0) return -1;

        int left = 0, currSum = 0;
        int maxLen = -1;

        for(int right = 0; right < n; right++) {
            currSum += nums[right];

            while(currSum > target && left <= right) {
                currSum -= nums[left];
                left++;
            }

            if(currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;

    }
};