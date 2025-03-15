class Solution {
public:
    int t[101];
    int solve(vector<int>& nums,int i,int end){
        if(i>end){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int take=nums[i]+solve(nums,i+2,end);
        int skip=solve(nums,i+1,end);
        return t[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        memset(t,-1,sizeof(t));
        int case1=solve(nums, 0, nums.size() - 2);
        memset(t,-1,sizeof(t));
        int case2=solve(nums, 1, nums.size() - 1);
        return max(case1,case2);
    }
};