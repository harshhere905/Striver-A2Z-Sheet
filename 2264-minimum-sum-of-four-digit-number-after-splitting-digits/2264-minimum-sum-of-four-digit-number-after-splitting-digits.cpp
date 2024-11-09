class Solution {
public:
    int minimumSum(int num) {
       vector<int>ans;
       string sample=to_string(num);
       for(char ch:sample){
        ans.push_back(ch-'0');
       }
       priority_queue<int,vector<int>,greater<int>>mp(ans.begin(),ans.end());
       int first=0;
       int second=0;
       int i=0;
       while(i!=ans.size()){
        first=first*10+mp.top();
        mp.pop();
        second=second*10+mp.top();
        mp.pop();
        i+=2;
       }
        return first+second;
    }
};