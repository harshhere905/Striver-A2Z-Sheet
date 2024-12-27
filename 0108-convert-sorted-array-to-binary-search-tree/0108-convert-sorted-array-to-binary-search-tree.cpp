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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        int mid=nums.size()/2;
        TreeNode* root=new TreeNode(nums[mid]);
        vector<int>prev;
        for(int i=0;i<mid;i++){
            prev.push_back(nums[i]);
        }
        vector<int>next;
        for(int i=mid+1;i<nums.size();i++){
            next.push_back(nums[i]);
        }
        root->left=sortedArrayToBST(prev);
        root->right=sortedArrayToBST(next);
        return root;
    }
};