class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefixsum=0;
        for(int x: nums){
            prefixsum+=x;
            int rem=prefixsum%k;
            if(rem<0)rem+=k;
            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};