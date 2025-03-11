class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        vector<int>arr(3,0);
        int l=0;
        for(int r=0;r<s.size();r++){
           arr[s[r]-'a']++;
           while(arr[0]>0&&arr[1]>0&&arr[2]>0){
              cnt+=s.size()-r;
              arr[s[l]-'a']--;
              l++;
           }
        }
        return cnt;
    }
};