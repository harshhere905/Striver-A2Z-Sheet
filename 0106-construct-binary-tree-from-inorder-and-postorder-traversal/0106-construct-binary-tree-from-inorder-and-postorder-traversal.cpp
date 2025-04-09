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
    TreeNode* solve(vector<int>& postorder,vector<int>&inorder,int& idx,int start,int end){
        if(start>end){
            return NULL;
        }
        int rootval=postorder[idx];
        int i=start;
        for(;i<=end;i++){
            if(inorder[i]==rootval){
                break;
            }
        }
        idx--;
        TreeNode* root=new TreeNode(rootval);
        root->right = solve(postorder, inorder, idx, i + 1, end);
        root->left = solve(postorder, inorder, idx, start, i - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        return solve(postorder,inorder,idx,0,postorder.size()-1);
    }
};