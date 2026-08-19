class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        // Build bitmask for every row
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            // Only seats 2 to 9 matter
            if (s >= 2 && s <= 9) {
                mp[row] |= (1 << (s - 2));
            }
        }

        // Every completely empty row can accommodate 2 groups
        long long ans = 2LL * (n - mp.size());

        int left   = 0b00001111;  // seats 2,3,4,5
        int middle = 0b00111100;  // seats 4,5,6,7
        int right  = 0b11110000;  // seats 6,7,8,9

        for (auto &[row, mask] : mp) {

            bool L = (mask & left) == 0;
            bool M = (mask & middle) == 0;
            bool R = (mask & right) == 0;

            if (L && R) {
                ans += 2;
            }
            else if (L || M || R) {
                ans += 1;
            }
        }

        return ans;
    }
};