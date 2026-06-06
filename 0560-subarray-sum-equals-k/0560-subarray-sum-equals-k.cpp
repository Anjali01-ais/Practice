class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefixsum=0;
        for(int i:nums){
            prefixsum+=i;
            if(mp.find(prefixsum-k)!=mp.end()){
                cnt+=mp[prefixsum-k];
            }
            mp[prefixsum]++;
        }
        
        
        return cnt;
    }
};