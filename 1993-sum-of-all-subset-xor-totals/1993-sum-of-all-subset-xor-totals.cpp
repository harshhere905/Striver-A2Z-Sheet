class Solution {
public:
    void solve(vector<int>& nums,int i,int currxor,int& totalxor){
        if(i==nums.size()){
            totalxor+=currxor;
            return;
        }
        solve(nums,i+1,currxor,totalxor);
        solve(nums,i+1,currxor^nums[i],totalxor);
    }
    int subsetXORSum(vector<int>& nums) {
        int totalxor=0;
        solve(nums,0,0,totalxor);
        return totalxor;
    }
};