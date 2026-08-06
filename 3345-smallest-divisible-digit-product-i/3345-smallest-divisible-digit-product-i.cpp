class Solution {
public:
    int digitPro(int n){
        int pro=1;
        while(n>0){
            pro*=(n%10);
            n/=10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitPro(n)%t==0){
                return n;
            }
            n++;
        }
    }
};