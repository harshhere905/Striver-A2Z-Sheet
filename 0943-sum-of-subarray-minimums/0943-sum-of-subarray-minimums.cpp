class Solution {
public:
    vector<int>get_left(vector<int>arr,int n){
         vector<int>result(n);
         stack<int>st;
         for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            result[i]=st.empty()?-1:st.top();
            st.push(i);
         }
         return result;
    }
     vector<int>get_right(vector<int>arr,int n){
         vector<int>result(n);
         stack<int>st;
         for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            result[i]=st.empty()?n:st.top();
            st.push(i);
         }
         return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>right_smaller=get_right(arr,n);
        vector<int>left_smaller=get_left(arr,n);
        long long sum=0;
        int M=1e9+7;
        for(int i=0;i<n;i++){
            long long d1=i-left_smaller[i];
            long long d2=right_smaller[i]-i;

            long long total=d1*d2;
            long long res=total*arr[i];
            sum=(sum+res)%M;
        }
        return sum;
    }
};