class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
           for(int j=mp[nums1[i]];j<nums2.size();j++){
             if(nums1[i]<nums2[j]){
                ans[i]=nums2[j];
                break;
            }
           }
        }
        return ans;
    }
};