class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int n:nums){
            string s=to_string(n);
            if(s.size()%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};