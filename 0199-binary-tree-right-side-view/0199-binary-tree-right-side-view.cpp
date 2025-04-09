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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>ans;
        queue<TreeNode*>qp;
        qp.push(root);
        while(!qp.empty()){
            int n=qp.size();
            TreeNode* node;
            while(n--){
                node=qp.front();
                qp.pop();
                if(node->left){
                    qp.push(node->left);
                }
                if(node->right){
                    qp.push(node->right);
                }
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};