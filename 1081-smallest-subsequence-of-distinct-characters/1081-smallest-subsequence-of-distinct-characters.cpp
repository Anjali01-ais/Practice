class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>fr(26,0);
        for(char c:s){
            fr[c-'a']++;

        }
        string st;
        vector<bool>vis(26,false);
        for(char c: s){
            fr[c-'a']--;
            if(vis[c-'a'])continue;
             while (!st.empty() &&
                   st.back() > c &&
                   fr[st.back() - 'a'] > 0) {

                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            vis[c - 'a'] = true;
        }
        return st;
    }
};