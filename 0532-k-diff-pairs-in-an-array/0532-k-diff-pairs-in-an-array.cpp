class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       // if (k < 0) return 0;  
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        int count = 0;
        for (auto& [num, f] : freq) {
            if ((k > 0 && freq.count(num + k)) || (k == 0 && f > 1)) {
                count++;
            }
        }
        return count;
    }
};
