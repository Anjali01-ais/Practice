#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // suf[i] will store the index in word1 matching word2[i] 
        // when exactly matching word2 from right to left.
        vector<int> suf(m, -1);
        int j = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            while (j >= 0 && word1[j] != word2[i]) {
                j--;
            }
            if (j >= 0) {
                suf[i] = j;
                j--;
            } else {
                // If we can't match exactly anymore, break early
                break;
            }
        }
        
        vector<int> ans;
        ans.reserve(m);
        
        j = 0;
        bool changed = false;
        
        // Greedily find the earliest valid index for each character in word2
        for (int i = 0; i < m; ++i) {
            bool picked = false;
            while (j < n) {
                if (word1[j] == word2[i]) {
                    // 1. Exact match found, we greedily take it.
                    ans.push_back(j);
                    j++;
                    picked = true;
                    break;
                } else if (!changed && (i + 1 == m || suf[i + 1] > j)) {
                    // 2. Not an exact match, but we can afford a change here because 
                    // the remainder of word2 can be successfully matched exactly.
                    ans.push_back(j);
                    changed = true;
                    j++;
                    picked = true;
                    break;
                }
                j++; // Advance `j` to search for the next possible index
            }
            
            // If we traversed the remaining word1 without picking an index, sequence is invalid
            if (!picked) {
                return {};
            }
        }
        
        return ans;
    }
};