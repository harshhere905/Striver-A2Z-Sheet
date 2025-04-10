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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>qt;
        qt.push(root);
        bool check=false;
        while(!qt.empty()){
            TreeNode* sample=qt.front();
            qt.pop();
            if(sample){
               if(check){
                  return false;
               }
               qt.push(sample->left);
               qt.push(sample->right);
            }
            else{
                check=true;
            }
        }
        return true;
    }
};