class Solution {
public:
    long long coloredCells(int n) {
       long long sum=1;
       for(int i=2;i<=n;i++){
         sum+=(i-1)*4;
       }
       return sum;       
    }
};