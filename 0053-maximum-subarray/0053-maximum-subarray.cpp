class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int maxi=0;
        for(int i=0;i<n;i++){
           curr+=nums[i];
           if(curr<0){
            curr=0;
           }
           maxi=max(maxi,curr);
        }
        int temp=*max_element(nums.begin(),nums.end());
        return maxi==0?temp:maxi;
    }
};