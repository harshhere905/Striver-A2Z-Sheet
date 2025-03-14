class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int ans=-1;
        int high=1e7;
        while(low<=high){
            bool first=true;
            double cnt=0;
            int mid=(low+high)/2;
            for(int i=0;i<dist.size();i++){
                if (i!=dist.size()-1) 
                    cnt+=ceil(double(dist[i]) / mid);
                else 
                    cnt+=double(dist[i]) / mid;
            }
            if(cnt<=hour){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }
};