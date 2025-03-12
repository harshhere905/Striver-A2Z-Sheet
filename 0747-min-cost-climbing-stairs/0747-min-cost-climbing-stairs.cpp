class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost,int idx){
        if(idx>=cost.size()){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        return t[idx]=cost[idx]+min(solve(cost,idx+1),solve(cost,idx+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
         return min(solve(cost,0),solve(cost,1));
    }
};