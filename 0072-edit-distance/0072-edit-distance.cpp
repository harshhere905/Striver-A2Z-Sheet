class Solution {
public:
    int t[501][501];
    int min_distance(string s1,string s2,int m,int n){
        if(m==0 || n==0){
            return m+n;
        }
        if(t[m][n]!=-1){
            return t[m][n];
        }
        if(s1[m-1]==s2[n-1]){
            return t[m][n]= min_distance(s1,s2,m-1,n-1);
        }
        else{
        int del=1+min_distance(s1,s2,m-1,n);
        int rep=1+min_distance(s1,s2,m-1,n-1);
        int ins=1+min_distance(s1,s2,m,n-1);
        return t[m][n] = min({del,ins,rep});
        }
    }
    int minDistance(string word1, string word2) {
        int m,n;
        m=word1.length();
        n=word2.length();
        memset(t,-1,sizeof(t));
        return min_distance(word1,word2,m,n);
    }
};