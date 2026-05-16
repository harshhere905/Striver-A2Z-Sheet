class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        if(nums.size()!=maxi+1){
           return false;
        }
        sort(nums.begin(),nums.end());
        if(nums[maxi-1]!=maxi){
            return false;
        }
        for(int i=0;i<maxi-1;i++){
            if(nums[i]!=i+1){
                return false;
            }
        }
        return true;
    }
};