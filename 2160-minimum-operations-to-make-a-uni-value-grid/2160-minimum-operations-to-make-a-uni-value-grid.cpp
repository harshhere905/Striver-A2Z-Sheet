class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem=grid[0][0]%x;
        vector<int>nums;
        for(auto it:grid){
            for(auto num:it){
                if(num%x!=rem){
                    return -1;
                }
                nums.push_back(num);
            }
        }
        sort(nums.begin(),nums.end());
        int ans=0;
        int med=nums[nums.size()/2];
        for(auto n:nums){
            ans+=abs(n-med)/x;
        }
        return ans;
    }
};