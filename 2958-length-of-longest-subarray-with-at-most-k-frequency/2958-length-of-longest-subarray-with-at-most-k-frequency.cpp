class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>fq;
        int ans=0;
        int l=0;
        for(int r=0; r<nums.size(); r++){
            fq[nums[r]]++;
            while(fq[nums[r]]>k){
                fq[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};