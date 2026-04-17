class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
           string s=to_string(nums[i]);
           reverse(begin(s),end(s));
           int mirror=stoi(s);
           if(mp.find(nums[i])!=mp.end()){
              auto it=mp.find(nums[i]);
              int dist=(i-it->second);
              ans=min(ans,dist);
           }
           mp[mirror]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};