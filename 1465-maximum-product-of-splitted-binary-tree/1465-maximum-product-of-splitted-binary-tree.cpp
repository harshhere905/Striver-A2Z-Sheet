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
    long max_prod=0;
    long total_sum=0;
    int calculate(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftsubtreesum=calculate(root->left);
        int rightsubtreesum=calculate(root->right);
        long subtreesum=root->val+leftsubtreesum+rightsubtreesum;
        long remaining_sum=total_sum-subtreesum;
        max_prod=max(max_prod,remaining_sum*subtreesum);
        return subtreesum;   
    }
    int maxProduct(TreeNode* root) {
        if(!root){
            return 0;
        }
        max_prod=0;
        total_sum=calculate(root);

        calculate(root);
        return max_prod%(1000000007);
    }
};