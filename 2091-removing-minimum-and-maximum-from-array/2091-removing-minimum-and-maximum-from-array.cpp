class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        int i = min(minIndex, maxIndex);
        int j = max(minIndex, maxIndex);

        int bothFront = j + 1;
        int bothBack = n - i;
        int oneFrontOneBack = (i + 1) + (n - j);

        return min({bothFront, bothBack, oneFrontOneBack});
    }
};