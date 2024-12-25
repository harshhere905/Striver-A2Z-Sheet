class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
         bool firstrow=false;
        bool firstcol=false;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    if(i==0){
                        firstrow=true;
                    }
                    if(j==0){
                        firstcol=true;
                    }
                mat[i][0]=0;
                mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
        if(firstrow){
            for(int i=0;i<mat[0].size();i++){
                mat[0][i]=0;
            }
        }
        if(firstcol){
            for(int i=0;i<mat.size();i++){
                mat[i][0]=0;
            }
        }
    }
};