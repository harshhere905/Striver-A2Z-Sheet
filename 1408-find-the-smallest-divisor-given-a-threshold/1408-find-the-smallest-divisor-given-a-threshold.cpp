class Solution {
public:
    bool check(int n,vector<int>nums,int threshold){
       int sum=0;
       for(int i=0;i<nums.size();i++){
         sum+=ceil((double)nums[i]/n);
       }
       if(sum<=threshold){
        return true;
       }
       else{
        return false;
       }
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto mini=1;
        auto maxi=max_element(nums.begin(),nums.end());
        int low=mini;
        int high=*maxi;
        int ans=-1; 
        while(low<=high){
            int mid=low+(high-low)/2;
            bool temp=check(mid,nums,threshold);
            if(temp){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};