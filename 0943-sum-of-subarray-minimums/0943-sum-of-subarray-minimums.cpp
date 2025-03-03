class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int ans=0;
        for(int i=0;i<arr.size();i++){
            int l=0;
            int r=0;
            for(int j=i-1;j>=0;j--){
               if(arr[j]>arr[i]){
                 l++;
               }
               else{
                break;
               }
            }
            for(int j=i+1;j<arr.size();j++){
               if(arr[j]>=arr[i]){
                 r++;
               }
               else{
                break;
               }
            }
            long long int res=(l+1)*(r+1);
            ans+=arr[i]*res;
        }
        const int MOD = 1e9 + 7;
        long long int res=(ans)%MOD;
        return res;
    }
};