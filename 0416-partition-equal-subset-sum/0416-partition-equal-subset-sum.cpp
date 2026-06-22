class Solution {
public:
    bool solve(int i,vector<int>& nums,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==0 ) return nums[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake=solve(i-1,nums,target,dp);
        bool take=false;
        if(nums[i]<=target){
            take=solve(i-1,nums,target-nums[i],dp);
        }
        return  dp[i][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0; i<nums.size(); i++)sum+=nums[i];
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,nums,target,dp);
    }
};