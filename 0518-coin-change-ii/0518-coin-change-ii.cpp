class Solution {
public:
int t[301][5001];
    int solve(int n,int i,int amount,vector<int>coins){
        if(amount==0){
            return 1;
        }
        if(t[i][amount]!=-1){
            return t[i][amount];
        }
        if(i==n){
            return 0;
        }
        if(amount<coins[i]){
            return t[i][amount] = solve(n,i+1,amount,coins);
        }
        int take=solve(n,i,amount-coins[i],coins);
        int skip=solve(n,i+1,amount,coins);
        return t[i][amount] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        int n=coins.size();
        return solve(n,0,amount,coins);
    }
};