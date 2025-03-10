class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    int countVowelSubstrings(string word) {
        int cnt=0;
        for(int i=0;i<word.size();i++){
            unordered_set<char>st;
            for(int j=i;j<word.size();j++){
               if(!isvowel(word[j])){
                break;
               }
               st.insert(word[j]);
               if(st.size()==5){
                cnt++;
               }
            }
        }
        return cnt;
    }
};