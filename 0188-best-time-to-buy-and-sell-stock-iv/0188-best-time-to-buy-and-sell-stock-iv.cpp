class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& nums,int i,int check,int cnt,int k){
        if(i>=nums.size()||cnt>=k){
            return 0;
        }
        if(dp[i][check][cnt]!=-1){
            return dp[i][check][cnt];
        }
        if(check){
            int buy=-nums[i]+solve(nums,i+1,0,cnt,k);
            int skip=solve(nums,i+1,1,cnt,k);
            return dp[i][check][cnt]=max(buy,skip);
        }
        else{
            int sell=nums[i]+solve(nums,i+1,1,cnt+1,k);
            int skip=solve(nums,i+1,0,cnt,k);
            return dp[i][check][cnt]=max(sell,skip);
        }
    }
    int maxProfit(int k,vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
        return solve(prices,0,1,0,k);
    }
};