class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int sum=0;
        int len=INT_MAX;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                if(j-i+1<len){
                    len=j-i+1;
                }
                sum-=nums[i];
                i++;
            }
        }
        return len==INT_MAX?0:len;
    }
};