class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int result=0;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int rem=sum%k;
            if(rem<0){
                rem=rem+k;
            }
            if(mp.find(rem)!=mp.end()){
                result=result+mp[rem];
            }
            mp[rem]++;
        }
        return result;
    }
};