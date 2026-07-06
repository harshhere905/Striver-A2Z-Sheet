class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        multimap<int,int> mp;
        int ans = intervals.size();
        for(auto it : intervals){
            mp.insert({it[0], it[1]});
        }
        for(auto it : intervals){
            int mini = it[0];
            int maxi = it[1];
            for(auto pq = mp.begin(); pq != mp.end(); ++pq){
                if(pq->first == mini && pq->second == maxi){
                    continue;
                }
                if(pq->first <= mini && pq->second >= maxi){
                    for(auto del = mp.begin(); del != mp.end(); ++del){
                        if(del->first == mini && del->second == maxi){
                            mp.erase(del);
                            ans--;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};