class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> ans;

        unordered_set<int> st1;
        for(int x : nums1) {
            st1.insert(x);
        }

        unordered_set<int> st2;
        for(int x : nums2) {
            st2.insert(x);
        }

        vector<int> a1;
        for(int x : st2) {
            if(st1.find(x) == st1.end()) {
                a1.push_back(x);
            }
        }

        vector<int> a2;
        for(int x : st1) {
            if(st2.find(x) == st2.end()) {
                a2.push_back(x);
            }
        }

        ans.push_back(a2);
        ans.push_back(a1);

        return ans;
    }
};