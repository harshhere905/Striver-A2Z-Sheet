class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int cnt=0;
        int i=0;
        multiset<int>st;
        for(int j=0;j<nums.size();j++){
            st.insert(nums[j]);
            while(*st.rbegin() - *st.begin() > limit){
                st.erase(st.find(nums[i]));
                i++;
            }
            cnt=max(cnt,j-i+1);
        }
        return cnt;
    }
};