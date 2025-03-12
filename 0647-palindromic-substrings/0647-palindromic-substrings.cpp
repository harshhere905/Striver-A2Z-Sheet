class Solution {
  public:
    int t[1001][1001];
    bool solve(string& s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]){
            return t[i][j]= solve(s,i+1,j-1);
        }
        return t[i][j]=false;
    }
    int countSubstrings(string &s) {
        int cnt=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(solve(s,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};