class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int maxi=0;
        int len=0;
        int j=0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]]>2){
                while(mp[s[j]]>2){
                    mp[s[i]]--;
                    i++;
                }
            }
            len=j-i+1;
            maxi=max(maxi,len);
            j++;    
        }
        return maxi;
    }
};