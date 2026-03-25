class Solution {
public:
    bool check_for_horiz(vector<int>& horizontal,vector<long long>& prefix_horiz,int m){
        for(int i=m-1;i<horizontal.size();i+=m){
            if(i==horizontal.size()-1){
                return false;
            }
            long long diff=prefix_horiz[prefix_horiz.size()-1]-prefix_horiz[i+1];
            if(diff==prefix_horiz[i+1]){
                return true;
            }
        }
        return false;
    }
    bool check_for_verti(vector<int>& vertical,vector<long long>& prefix_verti,int n){
        for(int i=n-1;i<vertical.size();i+=n){
            if(i==vertical.size()-1){
                return false;
            }
            long long diff=prefix_verti[prefix_verti.size()-1]-prefix_verti[i+1];
            if(diff==prefix_verti[i+1]){
                return true;
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>horizontal;
        vector<int>vertical;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                horizontal.push_back(grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vertical.push_back(grid[j][i]);
            }
        }
        int n1=horizontal.size();
        int n2=vertical.size();
        vector<long long>prefix_horiz(n1+1,0);
        vector<long long>prefix_verti(n2+1,0);
        for(int i=0;i<n1;i++){
            prefix_horiz[i+1]=prefix_horiz[i]+horizontal[i];
        }
        for(int i=0;i<n2;i++){
            prefix_verti[i+1]=prefix_verti[i]+vertical[i];
        }
        if(check_for_horiz(horizontal,prefix_horiz,n)){
            return true;
        }
        else if(check_for_verti(vertical,prefix_verti,m)){
            return true;
        }
        return false;
    }
};