class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // if(nums.size()<3){
        //     return 1;
        // }
        unordered_map<int,int>mp;
        for(auto n:nums){
            mp[n]++;
        }
        bool temp=true;
        for(auto it:mp){
            if(it.second>1){
                temp=false;
            }
        }
        if(temp){
            return 0;
        }
        int cnt=1;
        for(int i=0;i<nums.size();i+=3){
            for(int j=i;j<i+3;j++){
                if(j<nums.size()){
                mp[nums[j]]--;
                }
            }
            bool check=true;
            for(auto it:mp){
                if(it.second>1){
                    check=false;
                    cnt++;
                    break;
                }
            }
            if(check){
                break;
            }
        }
        return cnt;
    }
};