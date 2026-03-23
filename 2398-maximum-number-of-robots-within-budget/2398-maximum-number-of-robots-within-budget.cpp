class Solution {
public:
    bool check(vector<int>& chargeTimes,vector<int>& runningCosts,long long budget,int k){
        int n=chargeTimes.size();
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+runningCosts[i];
        }
        deque<int>dq;
        for(int j=0;j<n;j++){
            while(!dq.empty()&&chargeTimes[dq.back()]<=chargeTimes[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j>=k-1){
                int i=j-k+1;
                if(dq.front()<i){
                    dq.pop_front();
                }
                long long maxcharge=chargeTimes[dq.front()];
                long long sumcost=prefix[j+1]-prefix[i];
                long long total=maxcharge+(long long)k*sumcost;
                if(total<=budget){
                    return true;
                }
            }
        }
        return false;    
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int low=1;
        int high=chargeTimes.size();
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(chargeTimes,runningCosts,budget,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};