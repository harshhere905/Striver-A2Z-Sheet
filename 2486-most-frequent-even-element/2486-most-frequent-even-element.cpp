class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }
        int finalans=-1;
        int maxcount=0;
        for(auto it:mp){
           if(it.first%2==0){
              if(it.second>maxcount){
                maxcount=it.second;
                finalans=it.first;
              }
              else if(it.second==maxcount){
                if(finalans>it.first){
                    finalans=it.first;
                }
              }
           }
        }
        return finalans;
    }
};