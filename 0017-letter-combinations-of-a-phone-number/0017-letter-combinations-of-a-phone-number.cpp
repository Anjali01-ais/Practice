class Solution {
public:
    vector<string>res;
    void solve(int idx,string& curr,unordered_map<char,string>&mpp,string &digits){
        if(idx==digits.size()){
            res.push_back(curr);
            return;
        }
        string t=mpp[digits[idx]];
        for(char c:t){
            curr.push_back(c);
            solve(idx+1,curr,mpp,digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string curr="";
        //mapped-digits
        unordered_map<char,string>mpp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"}
        ,{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        solve(0,curr,mpp,digits);
        return res;
    }
};