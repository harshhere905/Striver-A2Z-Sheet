class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //middle element ke left side se max element nikal le or right side se nikal le o(n3) bekar solution hai o(n2) me hum ye leftmax ko precompute nhi krenge loop ke andar nikalenge o(n) jo ki ye h isme precompute krlenge bas!!
        vector<int>leftmax(nums.size(),0);
        vector<int>rightmax(nums.size(),0);
        leftmax[0]=nums[0];
        for(int i=1;i<nums.size();i++){
           leftmax[i]=max(leftmax[i-1],nums[i]);
        }
        rightmax[nums.size()-1]=nums[nums.size()-1];
        for(int j=nums.size()-2;j>=0;j--){
           rightmax[j]=max(rightmax[j+1],nums[j]);
        }
        //ab ye middle element ke liye loop chlega
        long long ans=0;
        for(int k=1;k<nums.size()-1;k++){
            ans=max(ans,(long long)(leftmax[k-1]-nums[k])*rightmax[k+1]);
        }
        return ans;
    }
};