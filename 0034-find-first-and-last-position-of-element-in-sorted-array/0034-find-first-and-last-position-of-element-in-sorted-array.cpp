class Solution {
public:
    int first_occ(vector<int>ans,int target){
        int l=0;
        int h=ans.size()-1;
        int temp=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(ans[mid]==target){
                temp=mid;
                h=mid-1;
            }
            else if(ans[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return temp;
    }
    int last_occ(vector<int>ans,int target){
        int l=0;
        int h=ans.size()-1;
        int temp=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(ans[mid]==target){
                temp=mid;
                l=mid+1;
            }
            else if(ans[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return temp;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int>ans(2);
         ans[0]=first_occ(nums,target);
         ans[1]=last_occ(nums,target);
         return ans;
    }
};