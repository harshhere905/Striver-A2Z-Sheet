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
    int countNodes(TreeNode* root) {
       if(!root){
        return 0;
       }
       int cnt=1;
       queue<TreeNode*>qp;
       qp.push(root);
       while(qp.size()!=0){
          TreeNode* temp=qp.front();
          qp.pop();
          if(temp->left){
             qp.push(temp->left);
             cnt++;
          }
          if(temp->right){
             qp.push(temp->right);
             cnt++;
          }
       }
       return cnt; 
    }
};