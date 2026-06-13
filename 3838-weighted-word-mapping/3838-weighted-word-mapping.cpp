class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char>mp1;
        unordered_map<char,int>mp2;
        string ans="";
        char t1='z';
        char t2='a';
        for(int i=0;i<26;i++){
            mp1[i]=t1;
            t1--;
        }
        for(auto it:weights){
            mp2[t2]=it;
            t2++;
        }
        for(auto it:words){
            int temp=0;
            for(int i=0;i<it.size();i++){
                temp+=mp2[it[i]];
            }
        temp=temp%26;
        ans+=mp1[temp];
        }
        return ans;
    }
};