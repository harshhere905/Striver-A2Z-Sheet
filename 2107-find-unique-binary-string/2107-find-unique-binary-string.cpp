class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res="";
        for(int i=0;i<nums.size();i++){
             char ch=(nums[i][i]=='0'?'1':'0');
             res.push_back(ch);
        }
        return res;
    }
};