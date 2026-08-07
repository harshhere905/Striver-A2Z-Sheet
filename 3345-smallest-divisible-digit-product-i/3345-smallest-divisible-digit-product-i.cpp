class Solution {
public:
    bool calculate(int num,int prod){
        int temp=num;
        int mult=1;
        while(temp>0){
            mult=mult*(temp%10);
            temp=temp/10;
        }
        if(mult%prod==0){
            return true;
        }
        return false;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(calculate(i,t)){
                return i;
            }
        }
        return 0;
    }
};