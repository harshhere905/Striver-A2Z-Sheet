class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count=0;
        set<int>st(banned.begin(),banned.end());
        for(int i=1;i<=n;i++){
              if(st.find(i)==st.end()){
                if(i<=maxSum){
                    maxSum=maxSum-i;
                    count++;
                    if(maxSum==0){
                        return count;
                    }
                }
              }
        }
        return count;
    }
};