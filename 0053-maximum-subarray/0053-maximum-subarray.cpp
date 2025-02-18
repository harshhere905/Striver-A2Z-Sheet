class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int final_sum=INT_MIN;
        int curr_sum=0;
        for(int n:nums){
           curr_sum+=n;
           final_sum=max(final_sum,curr_sum);
           if(curr_sum<0){
            curr_sum=0;
           }
        }
        return final_sum;
    }
}; 