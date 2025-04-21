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
    int maxdiff=-1;
    void finddiff(TreeNode* ancestor,TreeNode* child){
        if(!ancestor || !child) return;
        maxdiff=max(maxdiff,abs(ancestor->val-child->val));
        finddiff(ancestor,child->left);
        finddiff(ancestor,child->right);
    }
    void calculate(TreeNode* root){
        if(!root) return;
        finddiff(root,root->left);
        finddiff(root,root->right);
        calculate(root->left);
        calculate(root->right);
    }
    int maxAncestorDiff(TreeNode* root){
        calculate(root);
        return maxdiff;
    }
};