class Solution {
public:
    int t[13][10001];
    int solve(int i,int n,vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        if(i==n || amount<0){
            return INT_MAX;
        }
        if(t[i][amount]!=-1){
            return t[i][amount];
        }
        int take=solve(i,n,coins,amount-coins[i]);
        if (take != INT_MAX) {
            take += 1; 
        }
        int skip=solve(i+1,n,coins,amount);
        return t[i][amount]=min(take,skip);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n;
        n=coins.size();
        memset(t,-1,sizeof(t));
        int res = solve(0,n,coins,amount);
         return res==INT_MAX?-1:res;
    }

};