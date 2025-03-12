class Solution {
  public:
    bool solve(string& s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i]==s[j]){
            return solve(s,i+1,j-1);
        }
        return false;
    }
    int countSubstrings(string &s) {
        int cnt=0;
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