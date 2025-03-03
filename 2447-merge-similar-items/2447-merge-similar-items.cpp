class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int>mp;
        for(auto n:items1){
            mp[n[0]]=n[1];
        }
        for(auto n:items2){
            mp[n[0]]+=n[1];
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};