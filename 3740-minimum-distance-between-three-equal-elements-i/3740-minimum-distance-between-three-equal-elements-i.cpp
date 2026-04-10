class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(nums[j]==nums[i]){
                   for(int k=j+1;k<n;k++){
                       if(nums[k]==nums[j]){
                          ans=min(ans,abs(i - j) + abs(j - k) + abs(k - i));
                       }
                   } 
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};