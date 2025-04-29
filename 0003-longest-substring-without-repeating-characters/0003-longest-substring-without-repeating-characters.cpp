class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0;
        unordered_map<char,int>mp;
        int i=0;
        for(int j=0;j<s.size();j++){
            mp[s[j]]++;
            while(mp[s[j]]>=2){
                mp[s[i]]--;
                i++;
            }
             cnt=max(cnt,j-i+1);
        }
        return cnt;
    }
};