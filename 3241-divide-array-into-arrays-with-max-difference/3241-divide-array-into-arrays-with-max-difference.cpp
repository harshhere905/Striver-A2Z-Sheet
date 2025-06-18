class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int t=nums.size()/3;
        int o=nums.size()-1;
        int m=nums.size()-2;
        int n=nums.size()-3;
        while(t--){
            vector<int>temp;
            if(nums[o]-nums[m]<=k && nums[o]-nums[n]<=k && nums[m]-nums[n]<=k){
                temp.push_back(nums[n]);
                temp.push_back(nums[m]);
                temp.push_back(nums[o]);
                ans.push_back(temp);
                o=o-3;
                m=m-3;
                n=n-3;
            }
            else{
               return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};