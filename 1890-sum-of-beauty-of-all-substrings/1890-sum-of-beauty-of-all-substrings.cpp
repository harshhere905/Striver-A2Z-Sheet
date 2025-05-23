class Solution {
public:
    int beautySum(string s) {
        if(s.size()<=2){
            return 0;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            int freq[26]={0};
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                int max_f=INT_MIN;
                int min_f=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                      max_f=max(max_f,freq[k]);
                      min_f=min(min_f,freq[k]);
                    } 
                }
                ans+=max_f-min_f;
            }
        }
        return ans; 
    }
};