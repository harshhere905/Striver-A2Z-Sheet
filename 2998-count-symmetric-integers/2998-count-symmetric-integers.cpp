class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.length()%2!=0){
                continue;
            }
            int mid=s.length()/2;
            string temp1=s.substr(0,mid);
            string temp2=s.substr(mid);
            int sum1=0;
            int sum2=0;
            for(char c:temp1){
                int num1=c-'0';
                sum1+=num1;
            }
             for(char c:temp2){
                int num2=c-'0';
                sum2+=num2;
            }
            if(sum1==sum2){
                cnt++;
            }
        }
        return cnt;
    }
};