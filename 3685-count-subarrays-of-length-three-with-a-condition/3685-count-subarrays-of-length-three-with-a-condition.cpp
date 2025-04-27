class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=i+2;
            if(2*(nums[i]+nums[k])==nums[j]){
                cnt++;
            }
        }
        return cnt;
    }
};