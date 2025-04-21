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
    int calculate(TreeNode* root,int mini,int maxi){
        if(!root){
            return abs(maxi-mini);
        }
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        int l=calculate(root->left,mini,maxi);
        int r=calculate(root->right,mini,maxi);
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return calculate(root,root->val,root->val);
    }
};