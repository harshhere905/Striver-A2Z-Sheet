class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=0;
        int end=num;
        while(start<=end){
            int mid=(start+end)/2;
            long long mult=(long long)mid*mid;
            if(mult==num){
                return true;
            }
            else if(mult>num){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};