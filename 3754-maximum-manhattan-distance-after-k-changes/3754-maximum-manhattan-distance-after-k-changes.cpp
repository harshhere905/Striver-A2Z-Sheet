class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        vector<pair<char,char>>dir={{'N','E'},{'N','W'},{'S','E'},{'S','W'}};
        for(auto [d1,d2]:dir){
            int curr=0;
            int rem=k;
            for(auto it:s){
               if(it==d1 || it==d2){
                  curr++;
               }
               else if(rem>0){
                curr++;
                rem--;
               }
               else{
                curr--;
               }
               ans=max(ans,curr);
            }
        }
        return ans;
    }
};