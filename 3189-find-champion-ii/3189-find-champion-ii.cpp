class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        int champ=0;
        int cnt=0;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                champ=i;
                cnt++;
                if(cnt>1){
                    return -1;
                }
            }
        }
    return champ;
    }
};