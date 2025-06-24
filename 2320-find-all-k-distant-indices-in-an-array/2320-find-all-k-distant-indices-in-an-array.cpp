class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
               temp.push_back(i);
            }
        }
        vector<int>ans;
        for(int j=0;j<nums.size();j++){
            for(int m=0;m<temp.size();m++){
               if(abs(j-temp[m])<=k){
                  ans.push_back(j);
                  break;
               }
            }
        }
        return ans;
    }
};