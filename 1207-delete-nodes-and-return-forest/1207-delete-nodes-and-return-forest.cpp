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
    TreeNode* deletehelper(TreeNode* root,unordered_set<int>& st,vector<TreeNode*>& res){
        if(root==NULL){
            return NULL;
        }
        root->left=deletehelper(root->left,st,res);
        root->right=deletehelper(root->right,st,res);
        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL){
                res.push_back(root->left);
            }
            if(root->right!=NULL){
                res.push_back(root->right);
            }
            return NULL;
        }
        else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>res;
        unordered_set<int>st;
        for(int n:to_delete){
            st.insert(n);
        }
        deletehelper(root,st,res);
        if(st.find(root->val)==st.end()){
            res.push_back(root);
        }
        return res;
    }
};