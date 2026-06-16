class Solution {
public:
    string processStr(string s) {
      string res="";
      for(char c:s){
        if(c=='#'){
            res+=res;
        }else if(c=='%'){
            reverse(res.begin(),res.end());
        }else if(c=='*'){
            if(!res.empty()){
                res.pop_back();
            }
        }else{
            res+=c;
        }
      } 
      return res; 
    }
};