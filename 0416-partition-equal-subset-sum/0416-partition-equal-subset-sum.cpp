class Solution {
public:
    vector<vector<int>>t;
    bool solve(vector<int>& nums,int i,int sum){
        if(i>=nums.size() || sum<0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(t[i][sum]!=-1){
            return t[i][sum];
        }
        bool take=solve(nums,i+1,sum-nums[i]);
        bool skip=solve(nums,i+1,sum);
        return t[i][sum]=(take || skip);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%2!=0){
            return false;
        }
        t.assign(nums.size(),vector<int>(sum/2+1,-1));
        return solve(nums,0,sum/2);
    }
};