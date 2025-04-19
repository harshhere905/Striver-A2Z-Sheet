class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[i]=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            auto it=upper_bound(nums.begin()+i,nums.end(),temp[i]);
            if(it!=nums.end()){
                *it=-1;
                cnt++;
            }
        }
        return cnt;
    }
};