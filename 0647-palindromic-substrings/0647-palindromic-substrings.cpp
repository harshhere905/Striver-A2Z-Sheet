class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.size();
        int t[1001][1001];
        for(int len=1;len<=s.size();len++){
            for(int i=0;i+len-1<s.size();i++){
                int j=i+len-1;
                if(i==j){
                    t[i][j]=true;
                }
                else if(i+1==j){
                   t[i][j]=(s[i]==s[j]);
                }
                else{
                    t[i][j]=(s[i]==s[j] && (t[i+1][j-1]));
                }
            if(t[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};