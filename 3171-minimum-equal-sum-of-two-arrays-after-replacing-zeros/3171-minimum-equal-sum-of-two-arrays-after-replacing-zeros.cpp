class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
         int sum1=0;
         bool check1=false;
         bool check2=false;
         int sum2=0;
         for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0){
                sum1+=1;
                check1=true;
            }
            else{
                sum1+=nums1[i];
            }
         }
         for(int i=0;i<nums2.size();i++){
            if(nums2[i]==0){
                sum2+=1;
                check2=true;
            }
            else{
                sum2+=nums2[i];
            }
        }
        if(sum1<sum2){
            if(check1){
                return sum2;
            }
            else{
                return -1;
            }
        }
        else if(sum1>sum2){
            if(check2){
                return sum1;
            }
            else{
                return -1;
            }
        }
    return sum1;
    }
};