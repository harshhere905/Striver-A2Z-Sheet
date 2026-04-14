class Solution {
public:
    typedef long long ll;
    ll solve(int ri,int fi,vector<int>&robot,vector<int>&factories,vector<vector<ll>>&t){
           if(ri>=robot.size()){
            return 0;
           }
           if(fi>=factories.size()){
            return 1e15;
           }
           if(t[ri][fi]!=-1){
            return t[ri][fi];
            }
           ll current=abs(robot[ri]-factories[fi])+solve(ri+1,fi+1,robot,factories,t);
           ll skip=solve(ri,fi+1,robot,factories,t);

           return t[ri][fi]=min(current,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
         sort(robot.begin(),robot.end());
         sort(factory.begin(),factory.end());
         vector<int>factories;
         for(auto it:factory){
            int limit=it[1];
            int pos=it[0];
            while(limit--){
                factories.push_back(pos);
            }
         }
         int n=factories.size();
         int m=robot.size();
         vector<vector<ll>>t(m+1,vector<ll>(n+1,-1));
         return solve(0,0,robot,factories,t);
    }
};