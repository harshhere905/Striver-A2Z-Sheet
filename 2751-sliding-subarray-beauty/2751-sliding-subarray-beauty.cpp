class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int> freq(101, 0);
        for (int i = 0; i < k; i++) {
            freq[nums[i] + 50]++;  
        }
        for (int i = k; i <= nums.size(); i++) {
            int count = 0, result = 0;
            for (int j = 0; j < 101; j++) {
                count += freq[j];
                if (count >= x) {
                    result = j - 50; 
                    break;
                }
            }

            ans.push_back(result > 0 ? 0 : result);
            if (i < nums.size()) {
                freq[nums[i - k] + 50]--; 
                freq[nums[i] + 50]++; 
            }
        }
        return ans;
    }
};
