class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int i=0;
        int count=0;
        while(i!=nums.size()){
            int j=nums.size()-1;
            while(j>i){
               if(nums[i]==nums[j]){
                count++;
               }
               j--;
            }
            i++;
        }
        return count;
    }
};