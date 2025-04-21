class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        if(next_permutation(s.begin(),s.end())){
            long res=stol(s);
            return (res<=INT_MAX)?res:-1;
        }
        return -1;
    }
};