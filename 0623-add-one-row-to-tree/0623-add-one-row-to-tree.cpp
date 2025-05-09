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
    TreeNode* add(TreeNode* root,int val,int curr,int depth){
        if(root==NULL){
            return NULL;
        }
        if(curr==depth-1){
            TreeNode* lefttemp=root->left;
            TreeNode* righttemp=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            root->left->left=lefttemp;
            root->right->right=righttemp;
            return root;
        }
        root->left=add(root->left,val,curr+1,depth);
        root->right=add(root->right,val,curr+1,depth);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        int curr=1;
        return add(root,val,curr,depth);

    }
};