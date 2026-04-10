class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]].push_back(i);
        }
        for(auto it:mp){
            if(it.second.size()>=3){
               for(int i=0;i<it.second.size()-2;i++){
                   int j=i+1;
                   int k=i+2;
                   ans=min(ans,abs(it.second[i] - it.second[j]) + abs(it.second[j] - it.second[k]) + abs(it.second[k] - it.second[i]));
               }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};