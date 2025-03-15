class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>result;
        for(int i=0;i<group.size();i++){
            int size=group[i];
            mp[size].push_back(i);
            if(mp[size].size()==size){
                result.push_back(mp[size]);
                mp[size].clear();
            }
        }
        return result;
    }
};