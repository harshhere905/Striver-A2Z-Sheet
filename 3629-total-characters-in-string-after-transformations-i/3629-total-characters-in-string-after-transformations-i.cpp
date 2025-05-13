class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod=1000000007;
        vector<long long>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        while(t--){
            vector<long long>new_freq(26,0);
            for(int i=0;i<26;i++){
                    if(i==25){
                       new_freq[0]=(new_freq[0]+freq[25])%mod;
                       new_freq[1]=(new_freq[1]+freq[25])%mod;
                    }
                    else{
                       new_freq[i+1]=(new_freq[i+1]+freq[i])%mod;    
                    }
                }
                freq=new_freq;
            }
        long long len=0;
        for(int n:freq){
            len=(len+n)%mod;
        }
        return len;
    }
};