class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int diff=0;
        int dig_sum=0;
        int ele_sum=0;
        for(int n:nums){
            ele_sum+=n;
        }
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=0){
               int temp=nums[i]%10;
               dig_sum+=temp;
               nums[i]=nums[i]/10;
            }
        }
        return abs(ele_sum-dig_sum);
   }
};