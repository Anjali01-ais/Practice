/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        // Step 1: Convert linked list to array
        while (head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }
        // Step 2: Two pointer to find max twin sum
        int i = 0, j = arr.size() - 1;
        int maxi = 0;

        while (i < j) {
            maxi = max(maxi, arr[i] + arr[j]);
            i++;
            j--;
        }

        return maxi; 
    }
};