class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int booking=0;
        int last=0;
        for(auto it:meetings){
            int s=max(last+1,it[0]);
            int e=it[1];
            if(s<=e){
                booking+=e-s+1;
                last=it[1];
            }
        }
        return days-booking;
    }
};