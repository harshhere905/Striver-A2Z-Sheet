class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt_L=0;
        int cnt_R=0;
        int cnt_dash=0;
        for(auto it:moves){
            if(it=='L'){
                cnt_L++;
            }
            if(it=='R'){
                cnt_R++;
            }
            if(it=='_'){
                cnt_dash++;
            }
        }
        int diff=abs(cnt_L-cnt_R);
        return diff+cnt_dash;
    }
};