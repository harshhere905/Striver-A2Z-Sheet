class Solution {
public:
    string removeTrailingZeros(string num) {
        int ind=0;
        int i=num.length()-1;
        while(num[i]=='0'){
            i--;
        }
        return num.substr(0,i+1);
    }
};