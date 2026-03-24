class Solution {
public:
    int check(vector<int>&nums,int k,int mid){
        int sum=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
               sum=nums[i];
               cnt++;
            }
        }
        if(cnt<=k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,k,mid)){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};