class Solution {
public:
    char kthCharacter(int k) {
        string s;
        s.push_back('a');     
        while(s.length()<k){
            string temp;
            for(auto ch:s){
                temp.push_back(ch+1);
            }
            s+=temp;
        }
        return s[k-1];
    }
};