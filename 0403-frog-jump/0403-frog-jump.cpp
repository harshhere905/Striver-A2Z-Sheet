class Solution {
public:
    int n;
    vector<vector<int>>dp;
    unordered_map<int,int>mp;
    bool solve(vector<int>& stones,int curr_idx,int prev_jmp){
        if(curr_idx==n-1){
            return true;
        }
        if(dp[curr_idx][prev_jmp]!=-1){
            return dp[curr_idx][prev_jmp];
        }
        bool res=false;
        for(int nxt_jmp=prev_jmp-1;nxt_jmp<=prev_jmp+1;nxt_jmp++){
            if(nxt_jmp>0){
                int nxt_stone=stones[curr_idx]+nxt_jmp;
                if(mp.find(nxt_stone)!=mp.end()){
                    res=res||solve(stones,mp[nxt_stone],nxt_jmp);
                }
            }
        }
        return dp[curr_idx][prev_jmp]=res;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        dp.resize(n,vector<int>(n,-1));
        if(stones[1]!=1){
            return false;
        }
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        return solve(stones,0,0);
    }
};