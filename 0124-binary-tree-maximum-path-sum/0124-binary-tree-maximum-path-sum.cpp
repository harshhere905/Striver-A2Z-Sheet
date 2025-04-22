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
    int max_sum;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        int answer_found_at_bottom=l+r+root->val;
        int one_is_better=max(l,r)+root->val;
        int only_root_better=root->val;
        max_sum=max({max_sum,answer_found_at_bottom,one_is_better,only_root_better});
        return max(one_is_better,only_root_better);
    }
    int maxPathSum(TreeNode* root) {
        max_sum=INT_MIN;
        solve(root);
        return max_sum;
    }
};