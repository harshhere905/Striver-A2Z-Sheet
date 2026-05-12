class Solution {
public:
    bool check(int mid,priority_queue<pair<int,int>>& pq2){
        while(!pq2.empty()){
           auto t=pq2.top();
           pq2.pop();
           if(mid >= t.first + t.second){
              mid=mid-t.second;
           }
           else{
              return false;
           }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>>pq1;
        priority_queue<pair<int,int>>pq2;
        int sum=0;
        for(auto it:tasks){
            sum+=it[0];
            sum+=it[1];
            pq1.push({it[1] - it[0], it[0]});
        }
        int low=1;
        int high=sum;
        int ans=INT_MAX;
        while(low<=high){
            pq2=pq1;
            int mid=low+(high-low)/2;
            if(check(mid,pq2)){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
       return ans;
    }
};