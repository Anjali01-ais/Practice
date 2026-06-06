class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=(int)nums.size();
        int cnt=0;
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = prefix[j] - (i > 0 ? prefix[i-1] : 0);
                if (sum == k) cnt++;
            }
        }
        return cnt;
    }
};