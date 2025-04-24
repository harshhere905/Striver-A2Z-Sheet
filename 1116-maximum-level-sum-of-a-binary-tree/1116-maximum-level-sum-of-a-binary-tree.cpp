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
    int maxLevelSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int cnt=0;
        int maxsum=root->val;
        int ans=1;
        queue<TreeNode*>qp;
        qp.push(root);
        while(!qp.empty()){
            int currsum=0;
            int n=qp.size();
            while(n--){
                TreeNode* temp=qp.front();
                qp.pop();
                currsum+=temp->val;
                if(temp->left){
                    qp.push(temp->left);
                }
                if(temp->right){
                    qp.push(temp->right);
                }
            }
            cnt++;
            if(currsum > maxsum) {
                maxsum = currsum;
                ans = cnt;
            }
        }
        return ans;
    }
};