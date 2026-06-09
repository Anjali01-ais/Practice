class Solution {
public:
   bool isPallindrome(string &s, int l, int r){
    while(l <= r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;

    while(l <=r){
        if(s[l] != s[r]){
             return isPallindrome(s, l+1, r) || isPallindrome(s, l, r-1);
        }
        l++;
        r--;
    }
    return true;
}
};