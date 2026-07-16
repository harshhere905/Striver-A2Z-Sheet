class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int l1 = to_string(low).size();
        int l2 = to_string(high).size();
        vector<int> ans;

        for (int len = l1; len <= l2; len++) {
            for (int start = 1; start <= 9 - len + 1; start++) {
                int num = 0, j = start;
                for (int k = 0; k < len; k++) {
                    num = num * 10 + j;
                    j++;
                }
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};