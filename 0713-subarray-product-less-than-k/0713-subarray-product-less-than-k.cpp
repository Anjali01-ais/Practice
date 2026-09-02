class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k <= 1) return 0;
        int cnt=0;
        int l=0;
        long long prod=1;
        for(int r=0;r<n; r++){
            prod*=nums[r];
            while(prod>=k){
                prod/=nums[l];
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;

        
    }
};