class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int presum=0;
        int maxa=0;
        for(int i=0; i<gain.size(); i++){
            maxa=max(maxa,presum+gain[i]);
            presum=presum+gain[i];
        }
        return maxa;
    }
};