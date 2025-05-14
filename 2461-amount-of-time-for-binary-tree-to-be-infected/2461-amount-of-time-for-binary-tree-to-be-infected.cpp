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
    void convert(TreeNode* current,int parent,unordered_map<int,vector<int>>& adj){
         if (current == nullptr) {
            return;
        }
        if (parent != -1) {
            adj[current->val].push_back(parent);
        }
        if (current->left != nullptr) {
            adj[current->val].push_back(current->left->val);
        } 
        if (current->right != nullptr) {
            adj[current->val].push_back(current->right->val);
        }
        convert(current->left, current->val, adj);
        convert(current->right, current->val, adj);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        convert(root,-1,adj);
        queue<int>qp;
        qp.push(start);
        unordered_set<int>st;
        st.insert(start);
        int min=0;
        while(!qp.empty()){
            int n=qp.size();
            while(n--){
                int curr=qp.front();
                qp.pop();
                for(int n:adj[curr]){
                    if(st.find(n)==st.end()){
                        qp.push(n);
                        st.insert(n);
                    }
                }
            }
            min++;
        }
     return min-1;
    }
};