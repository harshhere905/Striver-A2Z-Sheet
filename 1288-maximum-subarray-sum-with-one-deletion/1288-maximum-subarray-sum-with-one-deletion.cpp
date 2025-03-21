class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int canDelete) {
        if (i >= nums.size()) return INT_MIN;
        if (dp[i][canDelete] != -1) return dp[i][canDelete];

        int take = nums[i] + max(0, solve(nums, i + 1, canDelete));
        int del = canDelete ? solve(nums, i + 1, 0) : INT_MIN;

        return dp[i][canDelete] = max(take, del);
    }

    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n, vector<int>(2, -1));

        int result = INT_MIN;
        for (int i = 0; i < n; i++) {
            result = max(result, solve(arr, i, 1));
        }
        return result;
    }
};
