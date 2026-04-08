class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod=1e9+7;
        for(auto it:queries){
           for(int idx=it[0];idx<=it[1];idx+=it[2]){
              nums[idx]=((long long)nums[idx] * it[3]) % (mod);
           }
        }
        int ans=0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};