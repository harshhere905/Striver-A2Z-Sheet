class Solution {
public:
    int mod = 1e9 + 7;
    int target;
    vector<int> power;
    int solve(int left, int right, vector<int>& nums) {
        if (left > right) return 0;
        if (nums[left] + nums[right] > target)
            return solve(left, right - 1, nums);
        int validSubseqs = power[right - left];
        int rest = solve(left + 1, right, nums);
        return (validSubseqs + rest) % mod;
    }
    int numSubseq(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        target = t;
        int n = nums.size();
        power.resize(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; ++i)
            power[i] = (power[i - 1] * 2) % mod;
        return solve(0, n - 1, nums);
    }
};
