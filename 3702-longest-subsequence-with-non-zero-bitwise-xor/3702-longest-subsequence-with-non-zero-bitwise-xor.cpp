class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xorr=0;
        for(int i:nums){
            xorr^=i;
        }
        if(xorr!=0) return n;
        for(int x:nums){
            if(x!=0){
                return n-1;
            }
        }
        return 0;
        
    }
};