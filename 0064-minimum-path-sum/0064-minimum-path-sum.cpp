class Solution {
public:
int t[201][201];
    int solve(int i,int j,vector<vector<int>>& grid,int m,int n){
        if(i>=m || j>=n){
            return INT_MAX;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        int right=solve(i,j+1,grid,m,n);
        int bottom=solve(i+1,j,grid,m,n);
        return t[i][j]=grid[i][j]+min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,grid,m,n);
    }
};