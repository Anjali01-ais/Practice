class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        // Helper function for Greatest Common Divisor
        auto gcd = [](long long a, long long b) {
            while (b) {
                a %= b;
                swap(a, b);
            }
            return a;
        };

        // Helper function for Least Common Multiple
        auto lcm = [&](long long a, long long b) {
            return (a / gcd(a, b)) * b;
        };

        long long l = 1, r = (long long)k * coins[0]; // Upper bound estimate
        long long ans = r;

        // Binary search for the kth smallest amount
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long count = 0;

            // Enumerate all non-empty subsets using bitmask
            for (int i = 1; i < (1 << n); ++i) {
                long long current_lcm = 1;
                int set_size = 0;
                bool overflow = false;

                for (int j = 0; j < n; ++j) {
                    if ((i >> j) & 1) {
                        current_lcm = lcm(current_lcm, coins[j]);
                        set_size++;
                        // Optimization: if LCM exceeds current search limit, skip
                        if (current_lcm > mid) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow) continue;

                // Inclusion-Exclusion Principle
                if (set_size % 2 == 1) {
                    count += mid / current_lcm;
                } else {
                    count -= mid / current_lcm;
                }
            }

            if (count >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1; 
            }
        }

        return ans;
    }
};;