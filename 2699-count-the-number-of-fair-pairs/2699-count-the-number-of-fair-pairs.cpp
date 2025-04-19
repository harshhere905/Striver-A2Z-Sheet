class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int l = lower - nums[i];
            int r = upper - nums[i];
            int left = lower_bound(nums.begin() + i + 1, nums.end(), l) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), r) - nums.begin();
            count += right - left;
        }
        return count;
    }
};
