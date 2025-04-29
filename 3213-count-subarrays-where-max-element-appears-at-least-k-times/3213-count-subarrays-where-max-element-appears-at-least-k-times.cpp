class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;
        long long cnt=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            while(mp[maxi]>=k){
                cnt+=n-j;
                mp[nums[i]]--;
                i++;
            }
        }
        return cnt;
    }
};