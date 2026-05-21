class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        int ans=0;
        for(auto it:arr1){
            string s=to_string(it);
            string temp="";
            for(int i=0;i<s.size();i++){
                 temp+=s[i];
                 st.insert(temp);
            }
        }
        for(auto it:arr2){
            string s=to_string(it);
            string temp="";
            for(int i=0;i<s.size();i++){
                temp+=s[i];
                if(st.find(temp)!=st.end()){
                   ans=max(ans,(int)temp.size());
                }
            }
        }
        return ans;
    }
};