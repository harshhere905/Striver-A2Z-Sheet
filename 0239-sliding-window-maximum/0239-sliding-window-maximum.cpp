class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int j=0;j<nums.size();j++){
            while(!dq.empty()&&nums[dq.back()]<=nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j>=k-1){
               int i=j-k+1;
               if(dq.front()<i){
                 dq.pop_front();
               }
               int maxval=nums[dq.front()];
               ans.push_back(maxval);
            }
        }
        return ans;
    }
};