class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        int ans=0;
        for(auto it:word){
            if(islower(it)){
                mp[it]++;
            }
        }
        for(auto it:word){
            if(isupper(it)){
                char ch=it+32;
                if(mp.find(ch)!=mp.end()){
                    ans++;
                    mp.erase(ch);
                }
            }
        }
        return ans;
    }
};