class Solution {
public:
    bool digitCount(string num) {
        int n=num.size();
        vector<int>occur(10,0);
        for(int i=0; i<n; i++){
            occur[num[i]-'0']++;
        }
        for(int i=0; i<n; i++){
          if (occur[i] != num[i] - '0') return false;   
        }
        return true;
    }
};