class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto it:s){
            if(it=='*'){
                if(ans.size()){
                ans.pop_back();
                }
                 continue;
            }
            if(it=='#'){
               ans+=ans;
               continue;
            }
            if(it=='%'){
               reverse(begin(ans),end(ans));
                continue;
            }
            ans+=it;
        }
        return ans;
    }
};