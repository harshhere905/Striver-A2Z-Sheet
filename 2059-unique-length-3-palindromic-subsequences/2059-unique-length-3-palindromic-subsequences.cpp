class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>letters;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            letters.insert(s[i]);
        }
        for(auto letter:letters){
            int left_idx=-1;
            int right_idx=-1;
            for(int i=0;i<s.length();i++){
                if(s[i]==letter){
                    if(left_idx==-1){
                        left_idx=i;
                    }
                    right_idx=i;
                }
            }
            unordered_set<char>mid;
            for(int middle=left_idx+1;middle<=right_idx-1;middle++){
                mid.insert(s[middle]);
            }
            cnt+=mid.size();
        }
        return cnt;
    }
};