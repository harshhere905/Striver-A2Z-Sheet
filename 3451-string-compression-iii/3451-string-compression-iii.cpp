class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int index=0;
        int i=0;
        while(i!=word.length()){
            char curr=word[i];
            int count=0;
            while(i<word.length()&&word[i]==curr){
                i++;
                count++;
                if(count==9){
                    break;
                }
            }
            ans+=to_string(count)+curr;
        }
        return ans;
    }
};