class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            long long cnt=0;
            for(int i=0;i<candies.size();i++){
               cnt+=candies[i]/mid;
            }
            if(cnt>=k){
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};