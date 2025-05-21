class Solution {
public:
    int minimumDeletions(string s) {
        int for_b=0;
        int deletions=0;
        for(char ch:s){
            if(ch=='b'){
                for_b++;
            }
            else{
              deletions=min(deletions+1,for_b);
            }
        }
        return deletions;
    }
};