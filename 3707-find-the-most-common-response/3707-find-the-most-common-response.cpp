class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int>mp;
        for(int i=0;i<responses.size();i++){
            set<string>st;
            for(string n:responses[i]){
                st.insert(n);
            }
            for(auto it:st){
                mp[it]++;
            }
        }
        int maxi=0;
        string ans;
        for(auto it:mp){
            if(it.second==maxi){
                if(ans>it.first){
                    ans=it.first;
                }
            }
            if(it.second>maxi){
                ans=it.first;
                maxi=it.second;
            }
        }
        return ans;
    }
};