class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int space=0;
        for(int i=0;i<spaces.size();i++){
            for(int j=space;j<spaces[i];j++){
                 ans.push_back(s[j]);
            }
            ans.push_back(' ');
            space=spaces[i];
        }
        for(int j=space;j<s.length();j++){
            ans.push_back(s[j]);
        }
        return ans;
    }
};