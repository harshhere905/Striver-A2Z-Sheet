class Solution {
public:
    bool check(string& str, int s, int e, int allow) {
        if (s >= e) {
            return true;
        }
        if (str[s] == str[e])
            return check(str, s + 1, e - 1, allow);
        if (allow) {
            return check(str, s, e - 1, 0) || check(str, s + 1, e, 0);
        }
        return false;
    }
    bool validPalindrome(string s) { return check(s, 0, s.size() - 1, 1); }
};