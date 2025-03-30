class Solution {
public: 
    int solve(char ch,string& s){
        int idx=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==ch){
                idx=i;
                break;
            }
        }
        return idx;
    }
    vector<int> partitionLabels(string s) {
        int i=0;
        vector<int>ans;
        while(i<s.size()){
            char ch=s[i];
            int temp=solve(ch,s);
            for(int j=i;j<=temp;j++){
               if(s[j]==ch){
                continue;
               }
               else{
                  int sample=solve(s[j],s);
                  if(sample<=temp){
                    continue;
                  }
                  else{
                    temp=sample;
                  }
               }
            }
            ans.push_back(temp-i+1);
            i=temp+1;
        }
        return ans;
    }
};