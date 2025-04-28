class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt=0;
        int i=0;
        long long sum=0;
        long long mult=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            mult=sum*(j-i+1);
            while(mult>=k){
               sum-=nums[i];
               i++;
               mult=sum*(j-i+1);
            }
            cnt+=(j-i+1);
        }
        return cnt;
    }
};