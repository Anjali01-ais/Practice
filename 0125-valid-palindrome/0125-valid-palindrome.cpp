class Solution {
public:
    bool isSpecial(char c){
       if((c >= 65 && c <= 90) ||  (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) return false;
       return true;
    }
    

    bool isPalindrome(string s) {
       int n=s.size();
       string t="";
       for(int i=0; i<n; i++){
        if(isSpecial(s[i])==false){
              t+=tolower(s[i]);
        }
       }
       int l=0;
       int r=t.size()-1;
       while(l<=r){
        if(t[l]!=t[r])return false;
        l++;
        r--;
       } 
       return true;
    }
};