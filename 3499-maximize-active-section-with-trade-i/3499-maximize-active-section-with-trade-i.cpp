class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
         int ones = 0;
        for(char c : s)
            if(c == '1') ones++;

        string t = "1" + s + "1";

        vector<pair<char,int>> runs;

        int cnt = 1;
        for(int i = 1; i < t.size(); i++) {
            if(t[i] == t[i-1]) {
                cnt++;
            } else {
                runs.push_back({t[i-1], cnt});
                cnt = 1;
            }
        }
        runs.push_back({t.back(), cnt});

        int maxGain = 0;

        for(int i = 1; i + 1 < runs.size(); i++) {

            if(runs[i].first == '1' &&
               runs[i-1].first == '0' &&
               runs[i+1].first == '0') {

                maxGain = max(maxGain,
                              runs[i-1].second + runs[i+1].second);
            }
        }

        return ones + maxGain;
    }
};