class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        int rsum=0;
        int ans=0;
        for(int i=n-k; i<n;i++){
            rsum+=cardPoints[i];
        }
         ans=rsum;
        for(int i=0; i<k; i++){
            lsum+=cardPoints[i];
            rsum-=cardPoints[n-k+i];
            ans=max(ans,lsum+rsum);
        }
        return ans;
    }
};