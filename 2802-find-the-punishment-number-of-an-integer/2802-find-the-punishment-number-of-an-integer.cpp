class Solution {
public:
    bool canPartition(string s, int target, int index, int sum) {
        if (index == s.length()) return sum == target;
        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num + sum > target) break;
            if (canPartition(s, target, i + 1, sum + num)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(to_string(square), i, 0, 0)) {
                ans += square;
            }
        }
        return ans;
    }
};
