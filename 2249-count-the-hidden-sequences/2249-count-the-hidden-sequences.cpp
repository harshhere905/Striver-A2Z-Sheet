class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr=0;
        int minval=0;
        int maxval=0;
        for(int n:differences){
            curr+=n;
            minval=min(minval,curr);
            maxval=max(maxval,curr);
            if((upper-maxval)-(lower-minval)+1<=0){
                return 0;
            }
        }
        return (upper-maxval)-(lower-minval)+1;
    }
};