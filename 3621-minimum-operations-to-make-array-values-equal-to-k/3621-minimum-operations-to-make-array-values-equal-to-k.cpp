class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        if(nums.size()==1){
            if(nums[0]==k){
                return 0;
            }
            else if(nums[0]>k){
                return 1;
            }
            else{
                return -1;
            }
        }
        if(nums[0]<k){
            return -1;
        }
        if(nums[0]>=k){
            int prev=nums[nums.size()-1];
            for(int i=nums.size()-2;i>=0;i--){
                if(nums[i]==prev){
                    continue;
                }
                cnt++;
                prev=nums[i];
            }
        }
        if(nums[0]>k){
            return cnt+1;
        }
        return cnt;
    }
};