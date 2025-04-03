class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>min_left(n);
        vector<int>min_right(n);
        min_left[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            min_left[i]=min(min_left[i-1],nums[i]);
        }
        min_right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            min_right[i]=min(min_right[i+1],nums[i]);
        }
        int sum=INT_MAX;
        for(int i=1;i<n-1;i++){
            int left=min_left[i-1];
            int right=min_right[i+1];
            if(left>=nums[i] || right>=nums[i]){
                continue;
            }
            sum=min(sum,left+right+nums[i]);
        }
        return (sum==INT_MAX)?-1:sum;
    }
};