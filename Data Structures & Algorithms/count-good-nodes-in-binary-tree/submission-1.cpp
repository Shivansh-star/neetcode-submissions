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
    int cnt = 0;
    void solve(TreeNode* root,int maxi){
        if(root == nullptr)return;
        if(root->val >= maxi)cnt++;
        int a = max(maxi,root->val);
        solve(root->left,a);
        solve(root->right,a);
        return;
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr)return 0;
        solve(root,root->val);
        return cnt;
    }
};
