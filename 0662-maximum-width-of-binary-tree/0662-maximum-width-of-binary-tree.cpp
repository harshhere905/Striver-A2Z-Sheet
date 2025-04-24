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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,ll>>qp;
        qp.push({root,0});
        ll maxwidth=0;
        while(!qp.empty()){
            ll L=qp.front().second;
            ll R=qp.back().second;
            maxwidth=max(maxwidth,R-L+1);
            int n=qp.size();
            while(n--){
                TreeNode* curr=qp.front().first;
                ll idx=qp.front().second;
                qp.pop();
                if(curr->left){
                    qp.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    qp.push({curr->right,2*idx+2});
                }
            }
        }
        return maxwidth;
    }
};