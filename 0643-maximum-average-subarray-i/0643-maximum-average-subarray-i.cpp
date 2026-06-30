class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        double sum=0;
        double maxAvg=-1e18;
        while(r<n){
            sum+=nums[r];
            if(r-l+1==k){
                maxAvg=max(maxAvg,(double)sum/k);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return maxAvg;
    }
};