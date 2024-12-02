class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int cnt=0;
        while(ss>>word){
            cnt++;
            if(word.find(searchWord)==0){
                return cnt;
            }
        }
        return -1;
    }
};