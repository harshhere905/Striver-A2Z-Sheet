class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto it=max_element(nums.begin(),nums.end());
        int ans=distance(nums.begin(),it);
        return ans;
    }
};