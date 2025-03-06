class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                mp[grid[i][j]]++;
            }
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
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