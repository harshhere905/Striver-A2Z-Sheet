class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       if(nums.size()==0){
        return 0;
       }
       int count=1;
       int maxcount=0;
       for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            continue;
        }
        if(nums[i]==nums[i-1]+1){
            count++;
        }
        else{
          maxcount=max(maxcount,count);
          //i=i+1;
          count=1;
        }
       } 
       return max(maxcount,count);
    }
};