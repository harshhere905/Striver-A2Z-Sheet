class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int len=1;
        int mask=0;
        while(j<nums.size()){
            while((mask & nums[j])!=0){
                mask=mask^nums[i];
                i++;
            }
            len=max(len,j-i+1);
            mask=(mask | nums[j]); 
            j++;
        }
        return len;
    }
};