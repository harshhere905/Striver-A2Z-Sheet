class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&res,int i,int check){
        if(i>=res.size()){
            return INT_MIN;
        }
        if(dp[i][check]!=-1){
            return dp[i][check];
        }
        int take=res[i]+max(0,solve(res,i+1,check));
        int del=check?solve(res,i+1,0):INT_MIN;
        return dp[i][check]=max(take,del);
    }
    int maximumSum(vector<int>& arr) {
        dp.resize(arr.size(),vector<int>(2,-1));
        int n=arr.size();
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            result=max(result,solve(arr,i,1));
        }
        return result;
    }
};