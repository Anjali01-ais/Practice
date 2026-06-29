class Solution {
public:
    int getBeauty( vector<int>&freq,int x){
        int cnt=0;
        for(int i=-50; i<0; i++){
           cnt+=freq[i+50];
           if(cnt>=x)return i;
        }
        return 0;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        vector<int>freq(101,0);
        for(int i=0; i<k;i++){
            if(nums[i]<0){
                freq[nums[i]+50]++;
            }
        }
        ans.push_back(getBeauty(freq,x));
        for(int i=k; i<nums.size(); i++){
            if(nums[i-k]<0){
                freq[nums[i-k]+50]--;
            }
            if(nums[i]<0){
                freq[nums[i]+50]++;
            }
            ans.push_back(getBeauty(freq,x));
        }
        return ans;
    }
};