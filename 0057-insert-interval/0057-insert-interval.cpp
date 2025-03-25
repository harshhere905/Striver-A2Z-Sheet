class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        for(auto it:intervals){
            if(merged.size()==0 || merged.back()[1]<it[0]){
                merged.push_back(it);
            }
            else{
                merged.back()[1]=max(merged.back()[1],it[1]);
            }
        }
        return merged;
    }
};