class Solution {
public:
    int n;
    vector<int>dp;
    set<string>st;
    bool solve(int idx,string s){
         if(idx>=n){
            return true;
         }
         if(st.find(s)!=st.end()){
            return true;
         }
         if(dp[idx]!=-1){
            return dp[idx];
         }
         for(int len=1;len<=n;len++){
            string temp=s.substr(idx,len);
            if(st.find(temp)!=st.end() && solve(idx+len,s)){
                return dp[idx]=true;
            }
         }
         return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       dp.resize(s.size(),-1);
       n=s.size();
       for(auto it:wordDict){
        st.insert(it);
       }
       return solve(0,s);
    
    }
};