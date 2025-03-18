class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices,int i,int check){
       if(i>=prices.size()){
        return 0;
       }
       if(dp[i][check]!=-1){
        return dp[i][check];
       }
       int profit=0;
       if(check){
          int buy=-prices[i]+solve(prices,i+1,0);
          int skip=solve(prices,i+1,1);
          return dp[i][check]=max(buy,skip);
       }
       else{
          int sell=prices[i]+solve(prices,i+1,1);
          int skip=solve(prices,i+1,0);
          return dp[i][check]=max(sell,skip);
       }
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1);
    }
};