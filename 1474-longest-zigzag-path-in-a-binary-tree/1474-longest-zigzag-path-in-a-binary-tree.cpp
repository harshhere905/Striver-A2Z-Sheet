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
    void calculate(TreeNode* root,char ch,int cnt,int& maxlen){
        if(!root){
            return;
        }
        maxlen=max(maxlen,cnt);
        if(root->left){
            calculate(root->left,'L',(ch=='R'?cnt+1:1),maxlen);
        }
        if(root->right){
            calculate(root->right,'R',(ch=='L'?cnt+1:1),maxlen);
        }
    }
    int longestZigZag(TreeNode* root) {
        int maxlen=0;
        if(root->left){
            calculate(root->left,'L',1,maxlen);
        }
        if(root->right){
            calculate(root->right,'R',1,maxlen);
        }
        return maxlen;
    }
};