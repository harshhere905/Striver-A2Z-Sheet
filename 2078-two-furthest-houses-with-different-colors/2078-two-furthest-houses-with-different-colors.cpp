class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=0;
        for(int i=0;i<colors.size();i++){
           for(int j=0;j<colors.size();j++){
               if(colors[j]!=colors[i]){
                  int dist=j-i;
                  ans=max(ans,dist);
               }
           }
        }
        return ans;
    }
};