class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<int>flat;
       for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              flat.push_back(grid[i][j]);
          }
       } 
       vector<long long>prefix(flat.size()+1,1);
       vector<long long>suffix(flat.size()+1,1);
       for(int i=0;i<flat.size();i++){
          prefix[i+1]=(prefix[i]*flat[i])%12345;
       }
       for(int j=flat.size()-1;j>=0;j--){
           suffix[j]=(suffix[j+1]*flat[j])%12345;
       }
       vector<vector<int>>arr(n,vector<int>(m));
       int i=0;
       int j=0;
       for(int k=0;k<flat.size();k++){
           int calc=(prefix[k]*suffix[k+1])%12345;
           arr[i][j]=calc;
           if(j==m-1){
             j=0;
             i++;
           }
           else{
             j++;
           }
       }
       return arr;
    }
};