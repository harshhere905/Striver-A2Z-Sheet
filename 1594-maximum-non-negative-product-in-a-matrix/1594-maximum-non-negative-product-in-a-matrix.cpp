class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>>dpmax(m,vector<long long>(n));
        vector<vector<long long>>dpmin(m,vector<long long>(n));
        dpmax[0][0]=dpmin[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dpmax[0][i]=dpmax[0][i-1]*grid[0][i];
            dpmin[0][i]=dpmin[0][i-1]*grid[0][i];
        }
        for(int j=1;j<m;j++){
            dpmax[j][0]=dpmax[j-1][0]*grid[j][0];
            dpmin[j][0]=dpmin[j-1][0]*grid[j][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long long val=grid[i][j];
                long long a=val*dpmax[i-1][j];
                long long b=val*dpmin[i-1][j];
                long long c=val*dpmax[i][j-1];
                long long d=val*dpmin[i][j-1];
                dpmax[i][j]=max({a,b,c,d});
                dpmin[i][j]=min({a,b,c,d});
            }
        }
        long long ans=dpmax[m-1][n-1];
        return (ans<0)?-1:(int)(ans%1000000007);
    }
};