class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st(nums1.begin(),nums1.end());
        vector<int>res;
        for(int i=0;i<nums2.size();i++){
           if(st.find(nums2[i])!=st.end()){
            st.erase(nums2[i]);
              res.push_back(nums2[i]);
           }
        }
    return res;
    }
};