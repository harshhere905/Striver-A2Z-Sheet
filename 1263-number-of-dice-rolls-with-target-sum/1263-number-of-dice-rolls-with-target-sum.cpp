class Solution {
public:
    vector<vector<int>>dp;
    int mod=1e9+7;
    int check(int n,int k,int target,int sum){
        if(n==0){
            return (sum==target)?1:0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        long long ways=0;
        for(int j=1;j<=k;j++){
            ways+=check(n-1,k,target,sum+j)%mod;
        }
        return dp[n][sum]=ways%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(31,vector<int>(901,-1));
        return check(n,k,target,0);
    }
};