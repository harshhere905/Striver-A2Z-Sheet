class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto n:nums){
            mp[n]++;
        }
     for(auto it:mp){
        if(it.second==1){
            return it.first;
        }
     }
     return 0;
    }

};