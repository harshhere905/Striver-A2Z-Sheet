class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int cnt=0;
       int maxi=INT_MIN;
       int mini=INT_MAX;
       int i=0;
       while(i!=nums.size()){
           maxi=max(nums[i],maxi);
           mini=min(nums[i],mini);
           if(maxi-mini>k){
              cnt++;
              maxi=INT_MIN;
              mini=INT_MAX;
           }
           else{
             i++;
             if(i==nums.size()){
                cnt++;
             }
           }
       }
       return cnt; 
    }
};