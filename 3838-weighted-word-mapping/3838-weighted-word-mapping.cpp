class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
      string res="";
      for(int i=0;  i<words.size(); i++){
        int total=0;
        for(int j=0; j<words[i].size(); j++){
            int idx=words[i][j]-'a';
            total+=weights[idx];
        }
        int val=total%26;
        char mapped='z'-val;
        res+=mapped;
      }
      return res;
    }
};