class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int x:nums){
            total+=x;
        }
        int lsum=0;
        for(int i=0; i<nums.size(); i++){
            int rsum=total-lsum-nums[i];
             if(lsum==rsum) return i;
             lsum+=nums[i];
        }
        return -1;
    }
};