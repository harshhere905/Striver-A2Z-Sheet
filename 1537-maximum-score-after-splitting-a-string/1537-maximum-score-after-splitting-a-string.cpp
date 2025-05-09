class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int totalOnes = count(s.begin(), s.end(), '1');
        int leftZeros = 0, rightOnes = totalOnes;
        int maxScore = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        return maxScore;
    }
};
