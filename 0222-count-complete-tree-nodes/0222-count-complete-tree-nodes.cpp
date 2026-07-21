/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findlcnt(TreeNode* root){
        int cnt = 0;
        while(root){
            cnt++;
            root = root->left;
        }
        return cnt;
    }

    int findrcnt(TreeNode* root){
        int cnt = 0;
        while(root){
            cnt++;
            root = root->right;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lcnt = findlcnt(root);
        int rcnt = findrcnt(root);

        if(lcnt == rcnt)
            return (1 << lcnt) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};