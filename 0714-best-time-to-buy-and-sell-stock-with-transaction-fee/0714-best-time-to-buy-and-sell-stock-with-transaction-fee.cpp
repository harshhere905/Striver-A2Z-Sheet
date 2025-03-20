class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices,int i,int check,int fee){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][check]!=-1){
            return dp[i][check];
        }
        if(check){
            int buy=-prices[i]+solve(prices,i+1,0,fee);
            int skip=solve(prices,i+1,1,fee);
            return dp[i][check]=max(buy,skip);
        }
        else{
            int sell=-fee+prices[i]+solve(prices,i+1,1,fee);
            int skip=solve(prices,i+1,0,fee);
            return dp[i][check]=max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,fee);
    }
};