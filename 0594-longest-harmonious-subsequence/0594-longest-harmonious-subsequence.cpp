class Solution {
public:
    int findLHS(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans=0;
       for(int i=0;i<nums.size();i++){
          for(int j=nums.size()-1;j>=0;j--){
              if(nums[j]-nums[i]==1){
                 ans=max(ans,j-i+1);
                 break;
              }
          }
       }
       return ans; 
    }
};