class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefixsum=0;
        for(int x:nums){
            prefixsum+=x;
            if(mp.find(prefixsum-goal)!=mp.end()){
                cnt+=mp[prefixsum-goal];
            }
            mp[prefixsum]++;
        }
        return cnt;
    }
};