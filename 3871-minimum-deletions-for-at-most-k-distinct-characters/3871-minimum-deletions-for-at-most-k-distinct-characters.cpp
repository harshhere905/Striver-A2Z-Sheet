class Solution {
public:
    int minDeletion(string s, int k) {        
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        if(mp.size()<=k){
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int diff=mp.size()-k;
        int ans=0;
        while(diff--){
           ans+=pq.top();
           pq.pop();
        }
        return ans;
    }
};