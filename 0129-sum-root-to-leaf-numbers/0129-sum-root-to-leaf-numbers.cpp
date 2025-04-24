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
    int cnt=0;
    int solve(TreeNode*root,int& ans){
        if(!root){
            return 0;
        }
        cnt=cnt*10+root->val;
        if(!root->left && !root->right){
          ans+=cnt;
        }
        if(root->left){
        solve(root->left,ans);
        }
        if(root->right){
        solve(root->right,ans);
        }
        cnt /= 10;
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        return solve(root,ans);
    }
};