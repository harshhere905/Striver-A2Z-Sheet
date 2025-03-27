class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int num:nums){
            mp2[num]++;
        }
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            mp1[num]++;
            mp2[num]--;
            int size_1=i+1;
            int size_2=nums.size()-i-1;
            if(mp1[num]*2>size_1 && mp2[num]*2>size_2){
                return i;
            }
        }
        return -1;
    }
};