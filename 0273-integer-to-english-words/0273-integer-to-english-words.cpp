class Solution {
public:

    vector<string> ones = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int num) {

        string ans;

        if (num >= 100) {
            ans += ones[num / 100] + " Hundred ";
            num %= 100;
        }

        if (num >= 20) {
            ans += tens[num / 10] + " ";
            num %= 10;
        }

        if (num > 0) {
            ans += ones[num] + " ";
        }

        return ans;
    }

    string numberToWords(int num) {

        if (num == 0)
            return "Zero";

        string ans;

        if (num >= 1000000000) {
            ans += helper(num / 1000000000);
            ans += "Billion ";
            num %= 1000000000;
        }

        if (num >= 1000000) {
            ans += helper(num / 1000000);
            ans += "Million ";
            num %= 1000000;
        }

        if (num >= 1000) {
            ans += helper(num / 1000);
            ans += "Thousand ";
            num %= 1000;
        }

        if (num > 0) {
            ans += helper(num);
        }

        // Remove trailing space
        if (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};