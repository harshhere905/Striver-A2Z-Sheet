class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        string temp="";
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:order){
            if(s.find(it)!=string::npos){
               while(mp[it]--){
               ans+=it;
               }
            }
        }
        for(auto it:s){
            if(ans.find(it)==string::npos){
                temp+=it;
            }
        }
        sort(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};