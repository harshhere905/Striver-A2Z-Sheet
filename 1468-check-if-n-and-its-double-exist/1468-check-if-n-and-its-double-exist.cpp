class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int>st(arr.begin(),arr.end());
        int cnt=0;
        for(int n:arr){
            if(n!=0 && st.find(n*2)!=st.end()){
                return true;
            }
            else if(n==0){
                cnt++;
            }
        }
        return (cnt>1)?true:false;
    }
};