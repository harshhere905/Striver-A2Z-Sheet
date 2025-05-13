/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* num){
        int total=0;
        int count=0;
        queue<TreeNode*>pq;
        pq.push(num);
        while(!pq.empty()){
            TreeNode* temp=pq.front();
            pq.pop();
            total+=temp->val;
            count++;
            if(temp->left){
                pq.push(temp->left);
            }
            if(temp->right){
                pq.push(temp->right);
            }
        }
        int avg=(total/count);
        if(avg==num->val){
            return true;
        }
        return false;
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        queue<TreeNode*>qp;
        qp.push(root);
        while(!qp.empty()){
            TreeNode* node=qp.front();
            qp.pop();
            if(check(node)){
                cnt++;
            }
            if(node->left){
                qp.push(node->left);
            }
            if(node->right){
                qp.push(node->right);
            }
        }
        return cnt;
    }
};