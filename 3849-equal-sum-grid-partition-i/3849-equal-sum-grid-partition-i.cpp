class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total_sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               total_sum+=grid[i][j];
            }
        }
        long long curr_sum1=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               curr_sum1+=grid[i][j];
            }
            if(curr_sum1==total_sum-curr_sum1){
                return true;
            }
        }
        long long curr_sum2=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
               curr_sum2+=grid[j][i];
            }
            if(curr_sum2==total_sum-curr_sum2){
                return true;
            }
        }
    return false;
    }
};