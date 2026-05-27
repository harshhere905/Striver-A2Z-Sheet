class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        unordered_map<char,int>cnt;
        for(auto it:word){
            if(islower(it)){
                cnt[it]++;
            }
        }
        int ans=0;
        for(auto it:word){
            if(islower(it)){
                mp[it]++;
            }
            else{
                char find=it+32;
                int limit=cnt[find];
                if(mp.find(find)!=mp.end()){
                   if(mp[find]==limit){
                   ans++;
                   mp[find]=-1;
                   }
                   else{
                     mp[find]=-1;
                   }
                }
                else{
                    if(cnt[find]){
                        mp[find]=-1;
                    }
                }
            }
        }
        return ans;
    }
};