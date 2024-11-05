class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int swap_index = -1;
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap_index = i;
                break;
            }
        }
        swap(nums[index], nums[swap_index]);
        reverse(nums.begin() + index + 1, nums.end());
    }
};