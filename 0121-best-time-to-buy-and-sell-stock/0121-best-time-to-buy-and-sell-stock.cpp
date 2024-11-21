class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=prices.size()-1;
        int j=i-1;
        int max_sum=0;
        while(j>=0){
            int sum=0;
            if(prices[i]>prices[j]){
                int diff=prices[i]-prices[j];
                sum=diff;
                j--;
            }
            else{
                j--;
                i=j+1;
            }
            max_sum=max(max_sum,sum);
        }
        return max_sum;
    }
};