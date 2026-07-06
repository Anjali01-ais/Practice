class Solution {
public:
    int missingNumber(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(int num:nums){
        mp[num]++;
       }
       int ans=0;
       for(int i=0; i<=nums.size(); i++){
        if(mp.find(i)==mp.end()) ans=i;
       } 
       return ans;
    }
};