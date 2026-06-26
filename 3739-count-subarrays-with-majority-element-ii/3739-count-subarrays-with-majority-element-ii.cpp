class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        Fenwick ft(2 * n + 5);

        long long ans = 0;
        int pref = 0;

        auto id = [&](int x) {
            return x + n + 2;
        };

        ft.update(id(0), 1);

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            ans += ft.query(id(pref) - 1);
            ft.update(id(pref), 1);
        }

        return ans;
    }

    
};