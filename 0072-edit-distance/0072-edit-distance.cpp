class Solution {
public:
    int t[501][501];
    int min_distance(string s1,string s2,int i,int j){
        int m=s1.length();
        int n=s2.length();
        if(i==m){
            return n-j;//insert
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(j==n){
            return m-i;//delete
        }
        if(s1[i]==s2[j]){
            return t[i][j]= min_distance(s1,s2,i+1,j+1);
        }
        else{
        int del=1+min_distance(s1,s2,i+1,j);
        int rep=1+min_distance(s1,s2,i+1,j+1);
        int ins=1+min_distance(s1,s2,i,j+1);
        return t[i][j] = min({del,ins,rep});
        }
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        return min_distance(word1,word2,0,0);
    }
};