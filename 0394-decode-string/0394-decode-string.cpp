class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        stack<int>num_stack;
        int num=0;
        for(auto it:s){
            if(isdigit(it)){
              num=num*10+(it-'0');
            }
            else if(it=='['){
                num_stack.push(num);
                num=0;
                st.push(it);
            }
            else if(it==']'){
                string temp;
                string sample;
                while(!st.empty()&&st.top()!='['){
                   sample+=st.top();
                   st.pop();
                }
                if(!st.empty())st.pop();
                reverse(sample.begin(),sample.end());
                for(int i=0;i<num_stack.top();i++){
                    temp+=sample;
                }
                num_stack.pop();
                for(auto k:temp){
                    st.push(k);
                }
            }
            else{
                st.push(it);
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};