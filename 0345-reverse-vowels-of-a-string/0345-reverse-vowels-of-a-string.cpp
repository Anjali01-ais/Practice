class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int n=s.size();
        int l=0; int r=n-1;
        while(l<r){
            while(l < r && !isVowel(s[l])) l++;
            while(l < r && !isVowel(s[r])) r--;
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};