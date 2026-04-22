class Solution {
public:
    int check(string s,vector<string>& d){
        for(auto it:d){
            int cnt=0;
            bool check=false;
            if(it.size()==s.size()){
               for(int i=0;i<s.size();i++){
                  if(it[i]!=s[i]){
                    cnt++;
                  }
               }
               if(cnt<=2){
                  return cnt;
               }
            }
        }
        return 0;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int limit=2;
        set<string>st(dictionary.begin(),dictionary.end());
        for(auto it:queries){
            if(st.find(it)!=st.end()){
                ans.push_back(it);
            }
            else{
                int t=check(it,dictionary);
                if(t){
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};