class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        int value = 0;
        for (int i = s.size()-1; i>=0; i--) {
            if (s[i] == '0') {
                ans++;
            } else if (ans < 30) {
                int bitVal = 1 << ans;
                if ((value + bitVal) <= k) {
                    value += bitVal;
                    ans++;
                }
            }
        }
        return ans;
    }
};
