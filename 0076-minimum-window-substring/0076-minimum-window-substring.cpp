class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        int zaruri=0;
        for(char c:t){
            need[c]++;
        }
        zaruri=need.size();
        int chahiye=0;
        int l=0;
        int minlen=INT_MAX;
        int start=0;
        for(int r=0; r<s.size(); r++){
            char c=s[r];
             window[c]++;
            if(need.count(c)&& window[c]==need[c]) chahiye++;
            while(chahiye==zaruri){
                  if(r-l+1<minlen){
                    minlen=r-l+1;
                    start=l;
                  }
            char ch=s[l];
            window[ch]--;
            if(need[ch]&& window[ch]<need[ch]){
                chahiye--;
            }
            l++;
            }
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};