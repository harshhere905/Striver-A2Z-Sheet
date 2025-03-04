class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        vector<int>ans(temp.size());
        for(int i=temp.size()-1;i>=0;i--){
            int span=1;
            while(!st.empty() && st.top().first<=temp[i]){
                span+=st.top().second;
                st.pop();                
            }
            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=span;
            }
            st.push({temp[i],span});
        }
        return ans;
    }
};