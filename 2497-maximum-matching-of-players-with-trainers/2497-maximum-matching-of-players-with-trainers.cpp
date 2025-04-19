class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int cnt=0;
        for(int n:players){
            auto it=lower_bound(trainers.begin(),trainers.end(),n);
            if(it!=trainers.end()){
                *it=-1;
                 cnt++;
            }
        }
        return cnt;
    }
};