class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int h=x;
        int ans=0;
        while(l<=h){
           long long int mid=(l+h)/2;
            if(mid*mid==x){
                ans=mid;
                break;
            }
            else if(mid*mid>x){
                h=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};