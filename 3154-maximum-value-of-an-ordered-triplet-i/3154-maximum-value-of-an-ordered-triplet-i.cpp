    class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        for(int j=1;j<nums.size()-1;j++){
            int leftmax=0;
            for(int i=0;i<j;i++){
                leftmax=max(leftmax,nums[i]);
            }
            int rightmax=0;
            for(int k=j+1;k<nums.size();k++){
                rightmax=max(rightmax,nums[k]);
            }
            ans=max(ans,(long long)(leftmax-nums[j])*rightmax);
        }
        return ans;
    }
};