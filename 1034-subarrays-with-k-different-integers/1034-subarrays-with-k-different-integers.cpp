class Solution {
public:
    int sliding_window(vector<int>nums,int k){
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int cnt=0;
        while(j<nums.size()){
        mp[nums[j]]++;
        while(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }
            cnt+=(j-i)+1;
            j++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding_window(nums,k)-sliding_window(nums,k-1);
    }
};