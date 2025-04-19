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
    int solve(TreeNode* root,int targetSum,long long sum){
        if(!root){
            return 0;
        }
        sum+=root->val;
        int cnt=(sum==targetSum)?1:0;
        int skip1=solve(root->left,targetSum,sum);
        int skip2=solve(root->right,targetSum,sum);
        return cnt+skip1+skip2;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        int fromroot=solve(root,targetSum,0);
        int fromleft=pathSum(root->left,targetSum);
        int fromright=pathSum(root->right,targetSum);
        return fromroot+fromleft+fromright;
    }
};