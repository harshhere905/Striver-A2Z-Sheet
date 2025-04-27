class Solution {
public:
    int calculate(TreeNode* root, int& maxi) {
        if (!root) {
            return 0;
        }
        int left = calculate(root->left, maxi);
        int right = calculate(root->right, maxi);
        maxi = max(maxi, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        calculate(root, maxi);
        return maxi;
    }
};
