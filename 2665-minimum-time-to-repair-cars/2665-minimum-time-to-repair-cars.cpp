class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=1;
        long long high=1e18;
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long cnt=0;
            for(int i=0;i<ranks.size();i++){
                cnt+=sqrt(mid/ranks[i]);
            }
            if(cnt>=cars){
                ans=min(mid,ans);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};