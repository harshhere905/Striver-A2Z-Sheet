class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char>st{'a','e','i','o','u'};
        int n=words.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            char f=words[i][0];
            char s=words[i].back();
            prefix[i+1]=prefix[i]+(st.count(f)&&st.count(s));
        }
        vector<int>res(queries.size());
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            res[i]=prefix[end+1]-prefix[start];   
        }
        return res;
    }
};