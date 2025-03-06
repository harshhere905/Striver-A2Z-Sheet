class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(mp.find(grid[i][j])!=mp.end()){
                    ans.push_back(grid[i][j]);
                }
                else{
                mp[grid[i][j]]++;
                }
            }
        }
        int maxi=(mp.end()->first);
        for(int i=1;i<=maxi;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        if(ans.size()==1){
            ans.push_back(maxi+1);
        }
        return ans;
    }
};