class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        int ans=INT_MAX;
        int limit=INT_MAX;
        for(auto it:text){
            if(it=='b' || it=='a' || it=='l' || it=='o' || it=='n'){
            mp[it]++;
            }
        } 
        if(mp.size()<5){
            return 0;
        }
        for(auto it:mp){
           if(it.first=='b' || it.first=='a' || it.first=='n'){
           ans=min(ans,it.second);
           }
        }
        int t1=mp['l']/2;
        int t2=mp['o']/2;
        limit=min(t1,t2);
        return min(ans,limit);
    }
};