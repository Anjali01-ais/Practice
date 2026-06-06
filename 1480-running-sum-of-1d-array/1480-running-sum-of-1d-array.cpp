class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res;
        int n=(int)nums.size();
        res.push_back(nums[0]);
        for(int i=1; i<n; i++){
            nums[i]=nums[i-1]+nums[i];
            res.push_back(nums[i]);
        }
        return res;
    }
};