class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7){
            return true;
        }
       while(true){
          int sum=0;
           while(n>0){
              int temp=n%10;
              sum+=temp*temp;
              n=n/10;
           }
           n=sum;
           if(n==1 || n==7){
            return true;
           }
           if(n%10==n && n!=1){
              return false;
           }
       }
       return false;
    }
};