class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool check=true;
        for(int i=0;i<s1.size()-2;i++){
            int j=i+2;
            if(s1[i]==s2[i] && s1[j]==s2[j]){
                continue;
            }
            else if(s1[i]!=s2[j] || s1[j]!=s2[i]){
                return false;
            }
        }
        return true;
    }
};