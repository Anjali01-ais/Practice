class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int cntless = 0;
        int cntequal = 0;

        for (int num : nums) {
            if (num < pivot) cntless++;
            else if (num == pivot) cntequal++;
        }

        int i = 0;                      // less than pivot
        int j = cntless;                // equal to pivot
        int k = cntless + cntequal;     // greater than pivot

        vector<int> res(n);

        for (int num : nums) {
            if (num < pivot) {
                res[i++] = num;
            }
            else if (num == pivot) {
                res[j++] = num;
            }
            else {
                res[k++] = num;
            }
        }

        return res;
    }
};