class Solution {
public:
    long long sumAndMultiply(int n) {
        string st=to_string(n);
        string num="";
        long long sum=0;
        for(auto it:st){
            if(it=='0'){
                continue;
            }
            else{
              sum+=it-'0';
              num+=it;
            }
        }
        long long number;
        if(num.size()==0){
           number=0;
        }
        else{
           number=stoll(num);
        }
        return number*sum;
    }
};