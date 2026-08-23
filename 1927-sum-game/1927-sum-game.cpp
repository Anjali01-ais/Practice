class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        int diff = leftSum - rightSum;

        if (abs(leftQ - rightQ) % 2 == 1)
            return true;

        if (leftQ > rightQ) {
            return diff != -9 * (leftQ - rightQ) / 2;
        }

        if (rightQ > leftQ) {
            return diff != 9 * (rightQ - leftQ) / 2;
        }

        return diff != 0;
    }
};