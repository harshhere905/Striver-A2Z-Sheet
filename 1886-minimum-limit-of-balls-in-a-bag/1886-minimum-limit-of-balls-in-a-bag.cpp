class Solution {
public:
    int ispossible(vector<int>nums,int maxops,int mid){
        int total_op=0;
        for(int n:nums){
            int ops=n/mid;
            if(n%mid==0){
                ops=ops-1;
            }
            total_op+=ops;
        }
        return total_op<=maxops;
    }
    int minimumSize(vector<int>& nums, int maxops) {
        int l=1;
        int r=*max_element(begin(nums),end(nums));
        int res=r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(ispossible(nums,maxops,mid)==true){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};