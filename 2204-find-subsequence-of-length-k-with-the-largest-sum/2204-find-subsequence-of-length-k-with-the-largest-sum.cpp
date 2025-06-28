class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++) {
            arr.emplace_back(nums[i], i);
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });
        arr.resize(k);
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        vector<int> result;
        result.reserve(k);
        for (auto &p : arr) {
            result.push_back(p.first);
        }
        return result;
    }
};
