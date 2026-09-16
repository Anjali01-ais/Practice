class Solution {
public:
    int numberOfSets(int n, int k) {
     long long mod = 1e9 + 7;
        int N = n + k - 1;
        int K = 2 * k;
        if (K > N) return 0;
        
        long long num = 1;
        long long den = 1;
        
        for (int i = 1; i <= K; ++i) {
            num = (num * (N - i + 1)) % mod;
            den = (den * i) % mod;
        }
        
        long long base = den;
        long long exp = mod - 2;
        long long inv = 1;
        
        while (exp > 0) {
            if (exp % 2 == 1) inv = (inv * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        
        return (num * inv) % mod;
    }
};