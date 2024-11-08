class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s=a;
        int cnt=1;
        int n=b.length()/a.length();
        for(int i=0;i<=n+1;i++){
           if(a.find(b)!=string::npos){
             return cnt;
           }
           a+=s;
           cnt++;
        }
        return -1;
    }
};