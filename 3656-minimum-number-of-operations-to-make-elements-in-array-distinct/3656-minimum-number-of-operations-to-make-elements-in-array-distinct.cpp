class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        unordered_set<int> seen;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (!seen.insert(nums[i]).second) {
                return i / 3 + 1;
            }
        }
        return 0;
    }
};
