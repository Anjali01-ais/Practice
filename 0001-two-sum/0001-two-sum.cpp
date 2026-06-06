class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i],i});
        }
        int n=(int)arr.size();
        sort(arr.begin(),arr.end());

        vector<int>res;
        int l=0;
        int r=n-1;
        while(l<r){
            int sum=arr[l].first+arr[r].first;
            if(sum==target){
                res.push_back(arr[l].second);
                res.push_back(arr[r].second);
            }
            if(sum<target){
                l++;
            }else{
                r--;
            }
        }
        
        return res;
        
    }
};