class Solution {
public:
    int getLength(vector<int>& nums) {
            int n = nums.size();
        int ans = 1;

        for(int i = 0; i < n; i++) {
            unordered_map<int,int> freq;
            unordered_map<int,int> countFreq;

            for(int j = i; j < n; j++) {
                int x = nums[j];

                int oldFreq = freq[x];
                if(oldFreq > 0) {
                    countFreq[oldFreq]--;
                    if(countFreq[oldFreq] == 0)
                        countFreq.erase(oldFreq);
                }

                freq[x]++;
                int newFreq = freq[x];
                countFreq[newFreq]++;

                // check validity
                if(freq.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
                else if(countFreq.size() == 2) {
                    auto it = countFreq.begin();
                    int f1 = it->first; it++;
                    int f2 = it->first;

                    int small = min(f1, f2);
                    int large = max(f1, f2);

                    if(large == 2 * small) {
                        ans = max(ans, j - i + 1);
                    }
                }
            }
        }

        return ans;

    }
};