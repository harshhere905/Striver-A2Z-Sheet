class Solution {
public:
    int kadane_max(vector<int>nums){
         int max_sum=INT_MIN;
        int cur_sum=0;
        for(int i=0;i<nums.size();i++){
            cur_sum+=nums[i];
            if(max_sum<cur_sum){
                max_sum=cur_sum;
            }
            if(cur_sum<0){
                cur_sum=0;
            }
        }
        return max_sum;
    }
    int kadane_min(vector<int>nums){
        int min_sum=INT_MAX;
        int cur_sum=0;
        for(int i=0;i<nums.size();i++){
            cur_sum+=nums[i];
            if(min_sum>cur_sum){
                min_sum=cur_sum;
            }
            if(cur_sum>0){
                cur_sum=0;
            }
        }
        return min_sum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=0;
        for(int n:nums){
            total_sum+=n;
        }
        int mini_sum=kadane_min(nums);
        int maxi_sum=kadane_max(nums);
        int circular_sub_sum=total_sum-mini_sum;
        if(maxi_sum>0){
            return max(maxi_sum,circular_sub_sum);
        }
        else{
            return maxi_sum;
        }
        return 0;
    }
};