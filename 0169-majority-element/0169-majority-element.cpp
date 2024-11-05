class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }
        int n=nums.size()/2;
        for(auto it:mp){
            if(it.second>n){
                return it.first;
            }
        }
        return 0;
    }
};