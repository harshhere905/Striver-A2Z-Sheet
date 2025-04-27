class Solution {
public:
    string multiply(string s1, string s2) {
        if(s1=="0" || s2=="0"){
            return "0";
        }
        int m=s1.size();
        int n=s2.size();
         vector<int> ans(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mult=(s1[i]-'0')*(s2[j]-'0');
                int sum=mult+ans[i+j+1];
                ans[i+j+1]=sum%10;
                ans[i+j]+=sum/10;
            }
        }
        string res="";
        for(int n:ans){
            if(!(res.empty() && n == 0)){
                res+=n+'0';
            }
        }
        return res;
    }
};