class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int temp=0;
        int cnt=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<0){
                cnt=cnt+(mid-temp)+1;
                temp=mid+1;
                left=mid+1;
            }
            else if(nums[mid]>=0){
                right=mid-1;
            }
        }
        int idx=lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        int pos_cnt=nums.size()-idx;
        if(cnt>=pos_cnt){
             return cnt;
        }
        return pos_cnt;
    }
};