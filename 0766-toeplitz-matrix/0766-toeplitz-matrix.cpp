class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=m-1;i>=0;i--){
            int j=i;
            int temp=mat[i][0];
            int k=0;
            while(j!=m && k!=n){
                if(mat[j][k]!=temp){
                    return false;
                }
                k++;
                j++;
            }
        }
        for(int i=1;i<n;i++){
            int j=i;
            int temp=mat[0][i];
            int k=0;
            while(j!=n && k!=m){
                if(mat[k][j]!=temp){
                    return false;
                }
                k++;
                j++;
            }
        }
    return true;
    }
};