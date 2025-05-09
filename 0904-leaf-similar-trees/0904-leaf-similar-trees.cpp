class Solution {
public:
    void dfs(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        if (!root->left && !root->right) {
            arr.push_back(root->val);
            return;
        }
        dfs(root->left, arr);
        dfs(root->right, arr);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        dfs(root1, arr1);
        dfs(root2, arr2);
        return arr1 == arr2;
    }
};
