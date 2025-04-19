class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        for(int n:g){
            auto it=lower_bound(s.begin(),s.end(),n);
            if(it!=s.end()){
                *it=-1;
                 cnt++;
            }
        }
        return cnt;
    }
};