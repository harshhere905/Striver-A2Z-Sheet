class Solution {
public:
    string longestPalindrome(string s) {
        int start=-1;
        int end=-1;
        int n=s.size();
        vector<vector<bool>>t(n,vector<bool>(n,false));
        for(int len=1;len<=n;len++){
            for(int i=0;len+i-1<n;i++){
                int j=len+i-1;
                if(i==j){
                    t[i][j]=true;
                }
                else if(i+1==j){
                    t[i][j]= (s[i]==s[j]);
                }
                else{
                    t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
                }
                if(t[i][j]==true){
                    start=i;
                    end=j;
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};