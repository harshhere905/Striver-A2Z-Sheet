class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,find;
        for(auto it:t){
            need[it]++;
        }
        int right=0;
        int left=0;
        int len=INT_MAX;
        int valid=0;
        int start=0;
        while(right!=s.size()){
            char temp=s[right];
            right++;
            if(need.count(temp)){
                find[temp]++;
                if(need[temp]==find[temp]){
                    valid++;
                }
            }
            while(valid==need.size()){
                if(right-left<len){
                    start=left;
                    len=right-left;
                }
                char sample=s[left];
                left++;
                if(need.count(sample)){
                   if(find[sample]==need[sample]){
                    valid--;
                   }
                   find[sample]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};