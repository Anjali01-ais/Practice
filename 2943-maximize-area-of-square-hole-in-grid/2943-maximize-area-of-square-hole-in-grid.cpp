class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
         sort(vBars.begin(),vBars.end());
         int maxhbarsconsecutive=1;
         int maxvbarsconsecutive=1;
         int curhbar=1;
         for(int i=1; i<hBars.size(); i++){
            if(hBars[i]-hBars[i-1]==1)curhbar++;
            else curhbar=1;
            maxhbarsconsecutive=max(maxhbarsconsecutive,curhbar);
         }
         int curvbar=1;
         for(int i=1; i<vBars.size(); i++){
            if(vBars[i]-vBars[i-1]==1)curvbar++;
            else curvbar=1;
            maxvbarsconsecutive=max(maxvbarsconsecutive,curvbar);
         }
         int side=min( maxvbarsconsecutive, maxhbarsconsecutive)+1;
         return side*side;

    }
};