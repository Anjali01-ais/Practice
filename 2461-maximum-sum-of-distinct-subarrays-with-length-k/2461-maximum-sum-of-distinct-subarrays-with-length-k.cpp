class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=(int)nums.size();
        long long maxSum=0;
        long long sum=0;
        long long dup=0;
        long long l=0;
        long long r=0;
        unordered_map<int,int>mp;
        while(r<n){
            sum+=nums[r];
            mp[nums[r]]++;
            if(mp[nums[r]]==2)dup++;
            if(r-l+1>k){
                sum-=nums[l];
                if(mp[nums[l]]==2)dup--;
                mp[nums[l]]--;
                l++;
            }
            if(r-l+1==k&&dup==0){
                maxSum=max(maxSum,sum);
            }
            r++;
        }
        return maxSum;
    }
};