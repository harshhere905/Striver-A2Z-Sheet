class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            int j=i+1;
            if(nums[i]==nums[j]){
                nums[i]=nums[i]*2;
                nums[j]=0;
            }
        }
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
            else{
                cnt++;
            }
        }
        while(cnt){
            ans.push_back(0);
            cnt--;
        }
        return ans;
    }
};