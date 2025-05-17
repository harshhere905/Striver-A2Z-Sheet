class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        for(int i=0;i<nums.size();i++){
            unordered_set<char>st;
            for(int j=0;j<nums[0].size();j++){
                if(nums[i][j]=='.'){
                    continue;
                }
                if(st.find(nums[i][j])!=st.end()){
                    return false;
                }
                st.insert(nums[i][j]);
            }
        }
        for(int i=0;i<nums[0].size();i++){
            unordered_set<char>st;
            for(int j=0;j<nums.size();j++){
                if(nums[j][i]=='.'){
                    continue;
                }
                if(st.find(nums[j][i])!=st.end()){
                    return false;
                }
                st.insert(nums[j][i]);
            }
        }
        int k=9;
        int r=0;
        int c=0;
    while(k--){
        unordered_set<char>st;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(nums[i][j]=='.'){
                    continue;
                }
                if(st.find(nums[i][j])!=st.end()){
                    return false;
                }
                st.insert(nums[i][j]);
            }
        }
        c=c+3;
        if(c==9){
            r=r+3;
            c=0;
        } 
    }
        return true;
    }
};