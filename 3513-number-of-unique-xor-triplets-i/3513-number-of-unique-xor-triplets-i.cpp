class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n= nums.size();
        int res=1;
        if(n<=2) return n;
        while(res<=n){
            res<<=1;
        }
        return res;

    }
};