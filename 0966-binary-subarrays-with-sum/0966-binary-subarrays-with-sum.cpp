class Solution {
public:
 int calculate(int n, vector<int> &nums,int k){
         if(k<0){
            return 0;
        }
        int l=0;
        int r=0;
        int cnt=0;
        int total_sum=0;
        while(r<n){
            total_sum+=nums[r];
            while(total_sum>k){
                total_sum-=nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n=nums.size();
        int diff1=calculate(n,nums,k);
        int diff2=calculate(n,nums,k-1);
        return diff1-diff2;   
    }
};