class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        for(int i = 0; i < nums.size(); i++) {
            long long prod = 1;

            for(int j = i; j < nums.size(); j++) {

                if(prod >= k)
                    break;

                prod *= nums[j];

                if(prod < k)
                    cnt++;
            }
        }
    return cnt;
    }
};