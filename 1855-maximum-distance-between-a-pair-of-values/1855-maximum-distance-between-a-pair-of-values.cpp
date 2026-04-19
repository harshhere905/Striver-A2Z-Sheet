class Solution {
public:
    int solve(int num,vector<int>& nums2,int& idx){
       int low=0;
       int high=nums2.size()-1;
       int temp=INT_MIN;
       while(low<=high){
          int mid=low+(high-low)/2;
          if(nums2[mid]>=num && mid>=idx){
            int d=mid-idx;
            temp=max(temp,d);
            low=mid+1;
          }
          else if(nums2[mid]>=num && mid<idx){
             low=mid+1;
          }
          else{
             high=mid-1;
          }
       }
       return temp;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
       int ans=INT_MIN;
       for(int i=0;i<nums1.size();i++){
          int dist=solve(nums1[i],nums2,i);
          ans=max(ans,dist);
       } 
       return ans==INT_MIN?0:ans;
    }
};