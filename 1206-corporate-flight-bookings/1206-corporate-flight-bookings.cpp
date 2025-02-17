class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>prefix_sum(n+1,0);
        for(auto b:bookings){
            prefix_sum[b[0]-1]+=b[2];
            prefix_sum[b[1]]-=b[2];
        }
        for(int i=1;i<prefix_sum.size();i++){
             prefix_sum[i]+=prefix_sum[i-1];
        }
        prefix_sum.pop_back();
        return prefix_sum;
    }
};