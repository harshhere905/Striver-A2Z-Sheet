class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int cnt=0;
        int i=0;
        multiset<int>st;
        for(int j=0;j<nums.size();j++){
            st.insert(nums[j]);
            int diff=*st.rbegin()-*st.begin();
            while(diff>limit){
                st.erase(st.find(nums[i]));
                diff=*st.rbegin()-*st.begin();
                i++;
            }
            cnt=max(cnt,j-i+1);
        }
        return cnt;
    }
};