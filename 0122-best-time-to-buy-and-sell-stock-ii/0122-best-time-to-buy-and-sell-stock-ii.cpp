class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int i=0;
        int j=i+1;
        int final_sum=0;
        while(j!=arr.size()){
            int diff=0;
           if(arr[j]>arr[i]){
            diff=arr[j]-arr[i];
            final_sum+=diff;
            i=j;
           }
           else{
            i=j;
           }
           j++;
        }
        return final_sum;
    }
};