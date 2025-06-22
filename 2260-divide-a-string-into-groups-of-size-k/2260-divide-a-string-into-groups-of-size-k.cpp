class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        while(s.size()%k!=0){
            s.push_back(fill);
        }
        for(int i=0;i<s.size();i+=k){
            ans.push_back(s.substr(i,k));
        }
        return ans;
    }
};