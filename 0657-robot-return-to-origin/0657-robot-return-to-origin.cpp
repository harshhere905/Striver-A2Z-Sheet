class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>mp;
        for(auto it:moves){
            if(it=='L' || it=='U'){
                mp[it]++;
            }
            else{
                if(it=='R'){
                    mp['L']--;
                }
                else{
                   mp['U']--;
                }
            }
        }
        for(auto it:mp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};