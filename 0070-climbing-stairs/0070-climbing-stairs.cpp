class Solution {
public: 
    int t[46];
    int solve(int n,long long check){
       if(check==n){
          return 1;
       }
       if(check>n){
          return 0;
       }
       if(t[check]!=-1){
        return t[check];
       }
       return t[check]=solve(n,check+1)+solve(n,check+2);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n,0);
    }
};