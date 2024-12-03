class Solution {
public:
    int n;
    int t[501][501];
    int solve(int i,int j,string &s){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==s[j]){
            t[i][j]= solve(i+1,j-1,s);
        }
        else{
            t[i][j]= 1+min(solve(i,j-1,s),solve(i+1,j,s));
        }
        return t[i][j];
    }
    int minInsertions(string s) {
        n=s.length();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,s);
    }
};