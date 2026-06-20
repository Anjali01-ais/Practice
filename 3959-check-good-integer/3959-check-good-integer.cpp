class Solution {
public:
    bool checkGoodInteger(int n) {
        long long sum=0;
        long long ssum=0;
        while(n>0){
            int d=n%10;
            sum+=d;
            ssum+=d*d;
            n/=10;
        }
        if(ssum-sum>=50) return true;
        return false;
    }
};