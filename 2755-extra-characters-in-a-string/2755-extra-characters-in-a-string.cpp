class Solution {
public:
    set<string>st;
    int n;
    int t[51];
    int solve(int idx,string& s){
        if(idx>=n){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        string temp="";
        int minextra=n;
        for(int i=idx;i<n;i++){
            temp.push_back(s[i]);
            int currextra = (st.find(temp) == st.end()) ? temp.length() : 0;
            int remextra=solve(i+1,s);
            int totalextra=currextra+remextra;
            minextra=min(minextra,totalextra);
        }
        return t[idx]=minextra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.length();
        memset(t,-1,sizeof(t));
        for(auto it:dictionary){
            st.insert(it);
        }
        return solve(0,s);
    }
};