class Solution {
public:
    int t[101];
    int solve(string s,int i){
        if(i>=s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int res=solve(s,i+1);
        if(i+1<s.size()){
        if(s[i]=='1' || s[i]=='2'&& s[i+1]<='6'){
        res+=solve(s,i+2);
        }
        }
        return t[i]=res;
    }
    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
       return solve(s,0); 
    }
};