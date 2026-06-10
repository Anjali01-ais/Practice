class Solution {
public:
    bool isLetter(char c){
    return ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
}
    string reverseOnlyLetters(string s) {
        int n=(int)s.size();
        int l=0; int r=n-1;
        while(l<r){
            while(l<r && !isLetter(s[l]))l++;
            while(l<r && !isLetter(s[r]))r--;
            swap(s[l],s[r]);
            l++;
            r--;

        }
        return s;
    }
};