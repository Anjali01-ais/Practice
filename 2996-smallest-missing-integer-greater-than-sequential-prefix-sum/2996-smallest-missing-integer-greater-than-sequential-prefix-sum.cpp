class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int>st;
        for(int it: nums){
            st.insert(it);
        }
        int sum=0;
        sum=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]  == nums[i- 1] + 1){
                sum+=nums[i];
            }else{
                break;
            }
        }
        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};