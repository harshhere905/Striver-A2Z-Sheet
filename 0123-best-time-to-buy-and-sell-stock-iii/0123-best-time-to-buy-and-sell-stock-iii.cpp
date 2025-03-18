class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& nums,int i,int check,int cnt){
        if(i>=nums.size()||cnt>=2){
            return 0;
        }
        if(dp[i][check][cnt]!=-1){
            return dp[i][check][cnt];
        }
        if(check){
            int buy=-nums[i]+solve(nums,i+1,0,cnt);
            int skip=solve(nums,i+1,1,cnt);
            return dp[i][check][cnt]=max(buy,skip);
        }
        else{
            int sell=nums[i]+solve(nums,i+1,1,cnt+1);
            int skip=solve(nums,i+1,0,cnt);
            return dp[i][check][cnt]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,0,1,0);
    }
};