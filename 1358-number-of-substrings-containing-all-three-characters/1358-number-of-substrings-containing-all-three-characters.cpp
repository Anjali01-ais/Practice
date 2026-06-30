class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
       vector<int>frq(3,0);
       int cnt=0;
       int l=0; int r=0;
       while(r<n){
        frq[s[r]-'a']++;
        while(frq[0]>0&& frq[1]>0&& frq[2]>0){
            frq[s[l]-'a']--;
            l++;
        }
        cnt+=l;
        r++;
       }
       return cnt;
    }
};