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
    vector<vector<int>>ans;
    void solve(TreeNode* root,vector<int>temp,int target,int sum){
        if(!root){
            return;
        }
        temp.push_back(root->val);
        sum+=root->val;
        if(!root->left&&!root->right){
           if(sum==target){
              ans.push_back(temp);
           }
           return;
        }
        solve(root->left,temp,target,sum);
        solve(root->right,temp,target,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum=0;
        solve(root,temp,targetSum,sum);
        return ans;
    }
};