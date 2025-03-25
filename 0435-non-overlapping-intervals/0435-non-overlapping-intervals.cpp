class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int i=0;
        int j=1;
        int cnt=0;
        while(j<n){
            vector<int>curr_int=intervals[i];
            vector<int>end_int=intervals[j];
            int cs=curr_int[0];
            int ce=curr_int[1];
            int ns=end_int[0];
            int ne=end_int[1];
            if(ce<=ns){
                i=j;
                j++;
            }
            else if(ce<=ne){
                cnt++;
                j++;
            }
            else if(ce>ne){
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};