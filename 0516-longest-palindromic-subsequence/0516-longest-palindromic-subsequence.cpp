class Solution {
public:
    int n;
    int t[1001][1001];
    int find_palindrome(string &s,int i,int j){
        if(i>j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==j){
            return 1;
        }
        if(s[i]==s[j]){
            return t[i][j]= 2+find_palindrome(s,i+1,j-1);
        }
        return t[i][j]= max(find_palindrome(s,i+1,j),find_palindrome(s,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        if(s.size()==1){
            return 1;
        }
        memset(t,-1,sizeof(t));
        n=s.size();
        return find_palindrome(s,0,n-1);
     }
};