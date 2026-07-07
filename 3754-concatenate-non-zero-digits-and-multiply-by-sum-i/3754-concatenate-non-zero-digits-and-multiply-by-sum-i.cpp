class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        int num=0;
        while(n>0){
            int d=n%10;
            if(d!=0){
                sum+=d;
            num=num*10+d;
            }
            n/=10;
        }
        long long numm=0;
        while(num>0){
            int d=num%10;
            numm=numm*10+d;
            num/=10;
        }
        return numm*sum;

    }
};