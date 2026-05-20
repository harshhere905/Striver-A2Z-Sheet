class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        vector<int>ans;
        vector<int>prefix(A.size(),0);
        for(int i=0;i<A.size();i++){
           int cnt=0;
           if(mp.find(A[i])!=mp.end()){
             cnt++;
           }
           else{
             mp[A[i]]++;
           }
           if(mp.find(B[i])!=mp.end()){
             cnt++;
           }
           else{
             mp[B[i]]++;
           }
           if(i==0){
             prefix[i]=cnt;
             ans.push_back(cnt);
           }
           else{
             int temp=prefix[i-1]+cnt;
             prefix[i]=temp;
             ans.push_back(temp);
           }
        }
        return ans;
    }
};