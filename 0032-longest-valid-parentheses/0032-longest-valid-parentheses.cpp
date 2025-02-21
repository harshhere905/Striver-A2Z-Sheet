class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); 
            } else {
                if (!st.empty()) st.pop(); 

                if (!st.empty()) {
                    maxLen = max(maxLen, i - st.top()); 
                } else {
                    st.push(i);
                }
            }
        }
        return maxLen;
    }
};
