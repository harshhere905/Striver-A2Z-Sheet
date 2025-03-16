class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        if(nums.size()==1){
            return nums[0];
        }
        for(int n:nums){
            st.insert(n);
        }
        bool check=false;
        for(auto it:st){
           if(it>0){
            check=true;
           }
        }
        if(check!=true){
            return *max_element(nums.begin(),nums.end());
        }
        int max_ans=0;
        int sum=0;
        for(auto it:st){
           sum+=it;
           if(sum<0){
             sum=0;
           }
           max_ans=max(sum,max_ans);
        }
        return max_ans;
    }
};