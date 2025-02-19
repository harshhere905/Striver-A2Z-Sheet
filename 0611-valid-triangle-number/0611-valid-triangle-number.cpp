class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=2;i<nums.size();i++){
            int l=0;
            int r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    cnt+=(r-l);
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return cnt;
    }
};