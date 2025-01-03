class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long int>postfix(n+1,0);
        for(int i=n-1;i>=0;i--){
            postfix[i]=postfix[i+1]+nums[i];           
        }
        int cnt=0;
        long long int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            if(sum>=postfix[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};