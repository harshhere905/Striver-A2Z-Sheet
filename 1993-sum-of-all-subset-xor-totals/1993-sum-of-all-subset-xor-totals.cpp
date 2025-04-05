class Solution {
public:
    void generateSubsets(int index, const vector<int>& nums, vector<int>& current, vector<vector<int>>& subsets) {
    if (index == nums.size()) {
        subsets.push_back(current);
        return;
    }
    generateSubsets(index + 1, nums, current, subsets);
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current, subsets);
    current.pop_back(); 
}
int totalSubsetXOR(const vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> current;
    generateSubsets(0, nums, current, subsets);
    int totalXor = 0;
    for (const auto& subset : subsets) {
        int xorValue = 0;
        for (int num : subset) {
            xorValue ^= num;
        }
        totalXor += xorValue;
    }
    return totalXor;
}
    int subsetXORSum(vector<int>& nums) {
        return totalSubsetXOR(nums);
    }
};