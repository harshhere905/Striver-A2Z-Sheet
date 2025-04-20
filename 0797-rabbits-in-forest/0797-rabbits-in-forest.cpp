class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int cnt=0;
        for(int n:answers){
            mp[n]++;
        }
        for(auto it:mp){
            if(it.first==0){
            cnt+=it.second;
            }
            else if(it.second<it.first+1){
                cnt+=it.second;
                cnt+=((it.first+1)-it.second);
            }
            else if(it.second==it.first+1){
                cnt+=it.second;
            }
            else{
                cnt+=it.second;
                int diff=it.second%(it.first+1);
                cnt+=(it.first+1)-diff;
            }
        }
        return cnt;
    }
};