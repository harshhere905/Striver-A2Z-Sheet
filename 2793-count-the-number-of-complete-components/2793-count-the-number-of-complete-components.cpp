class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&mp,int& i,vector<bool>&visited,int& v,int& e){
      queue<int>que;
      que.push(i);
      visited[i]=true;
      while(!que.empty()){
         int curr=que.front();
         que.pop();
         v++;
         e+=mp[curr].size();
         for(int n:mp[curr]){
            if(!visited[n]){
                visited[n]=true;
                que.push(n);
            }
         }
      }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        int res=0;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            int v=0;
            int e=0;
            bfs(mp,i,visited,v,e);
            if(v*(v-1)==e){
               res++;
            }
        }
        return res;
    }
};