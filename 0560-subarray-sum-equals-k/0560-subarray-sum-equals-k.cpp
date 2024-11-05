class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int diff=sum-k;
            if(mp.find(diff)!=mp.end()){
                count=count+mp[diff];
            }
            mp[sum]++;
        }
        return count;
    }
};