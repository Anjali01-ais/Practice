class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
     int n = nums.size();
     vector<int> premax(n), sufmin(n);

      premax[0]=nums[0];
     for(int i=1; i<n; i++){
        premax[i]=max(premax[i-1],nums[i]);
     }
      sufmin[n-1]=nums[n-1];
     for(int j=n-2; j>=0; j--){
         sufmin[j]=min(sufmin[j+1],nums[j]);
     }
     for (int i = 0; i < n; i++) {
        if (premax[i] - sufmin[i] <= k)
            return i;
    }
    return -1;
       
    }
};