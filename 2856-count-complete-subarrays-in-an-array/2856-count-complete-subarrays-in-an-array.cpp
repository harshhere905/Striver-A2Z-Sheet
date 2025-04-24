class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        for(int n:nums){
            st.insert(n);
        }
        int distinct_size=st.size();
        unordered_map<int,int>mp;
        int i=0;
        int cnt=0;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            while(mp.size()>=distinct_size){
                cnt+=nums.size()-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
        }
        return cnt;
    }
};