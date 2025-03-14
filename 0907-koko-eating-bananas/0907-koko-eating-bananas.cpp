class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            long long cnt=0;
            int mid=(low+high)/2;
            for(int i=0;i<piles.size();i++){
                cnt+=(piles[i]+mid-1)/mid;
            }
            if(cnt<=h){
               ans=min(ans,mid);
               high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return ans;
    }
};