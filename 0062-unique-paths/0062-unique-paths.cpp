class Solution {
public:
     int solve(int r,int c,int m,int n,vector<vector<int>>&t){
        if(r==m-1&&c==n-1){
            return 1;
        }
        if(t[r][c]!=-1){
            return t[r][c];
        }
        int path=0;
        if(r!=m-1){
            path+=solve(r+1,c,m,n,t);
        }
        if(c!=n-1){
            path+=solve(r,c+1,m,n,t);
        }
        t[r][c]=path;
        return t[r][c];
     }
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, -1));
        int cnt=0;
        return  solve(0,0,m,n,t);   
    }
};