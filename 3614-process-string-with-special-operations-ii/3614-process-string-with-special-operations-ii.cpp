class Solution {
public:
    char processStr(string s, long long k) {
       int n = (int)s.size();
        vector<long long> len(n); // int → long long better
        long long curr = 0;

        for(int i = 0; i < n; i++){
            char c = s[i];

            if(c >= 'a' && c <= 'z'){
                curr++;
            }
            else if(c == '*'){
                curr = max(0LL, curr - 1);
            }
            else if(c == '#'){
                curr *= 2;
            }
            else if(c == '%'){
                // reverse → no change
            }

            len[i] = curr; 
        }

        if(k >= curr) return '.';

        for(int i = n - 1; i >= 0; i--){
            char c = s[i];
            long long clen = len[i];

            if(c >= 'a' && c <= 'z'){
                if(k == clen - 1)
                    return c;
            }
            else if(c == '*'){
                // nothing
            }
            else if(c == '#'){
                long long oldLen = clen / 2;
                k %= oldLen;
            }
            else if(c == '%'){
                k = clen - 1 - k;
            }
        }

        return '.';
    
    }
};