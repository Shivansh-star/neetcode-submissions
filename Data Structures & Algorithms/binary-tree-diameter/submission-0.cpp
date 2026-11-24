
class Solution {
public:
    int dai = 0;

    int solve(TreeNode* root){
        if(root == nullptr)return 0;

        int left = 0;
        int right = 0;

        if(root->left){
            left = solve(root->left);
        }

        if(root->right){
            right = solve(root->right);
        }

        dai = max(dai,left+right);

        return max(left,right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)return 0;

        int ans = solve(root);
        return dai;
    }
};
