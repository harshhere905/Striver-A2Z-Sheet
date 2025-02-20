class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        vector<int> sortedArr;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            int idx = lower_bound(sortedArr.begin(), sortedArr.end(), nums[i]) - sortedArr.begin();
            ans.push_back(idx);
            sortedArr.insert(sortedArr.begin() + idx, nums[i]); 
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
