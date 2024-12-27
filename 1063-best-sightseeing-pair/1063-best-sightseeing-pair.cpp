class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>sample(n);
        sample[0]=values[0]+0;
        for(int i=1;i<n;i++){
             int sum=values[i]+i;
             if(sum<sample[i-1]){
                sample[i]=sample[i-1];
             }
             else{
                sample[i]=sum;
             }
        }
        int finalmax=INT_MIN;
        for(int j=1;j<n;j++){
            int diff=values[j]-j;
            int finalsum=diff+sample[j-1];
            finalmax=max(finalmax,finalsum);
        }
        return finalmax;
    }
};