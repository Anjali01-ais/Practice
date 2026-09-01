class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int sum=0;
        int i=0;
        while(i<n){
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
            }
            i++;
            if(sum<0){
              sum=0;
            }
        }
        return maxi;
    }
};