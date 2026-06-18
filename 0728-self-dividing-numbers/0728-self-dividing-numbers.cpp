class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
       vector<int>ans;
       for(int n=left; n<=right; n++){
        int num=n;
        bool candiv=true;
        while(num>0){
            int d=num%10;
            if(d==0||n%d!=0){
                candiv=false;
                break;
            }
            num/=10;
        }
        if(candiv){
            ans.push_back(n);
        }
       } 
       return ans;
    }
};