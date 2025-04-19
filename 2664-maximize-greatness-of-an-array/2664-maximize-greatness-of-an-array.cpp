class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int cnt=0;
        int n=nums.size();
        while(i<n && j<n){
           if(nums[i]<nums[j]){
              i++;
              cnt++;
           }
           j++;
        }
        return cnt;
    }
};