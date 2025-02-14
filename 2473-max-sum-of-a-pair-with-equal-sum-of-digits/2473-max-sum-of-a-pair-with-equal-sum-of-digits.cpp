class Solution {
public:
    int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;  
        n = n / 10;       
    }
    return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int n:nums){
           int s=sumOfDigits(n);
           mp[s].push_back(n);
           if(mp[s].size()>2){
             sort(mp[s].rbegin(),mp[s].rend());
             mp[s].resize(2);
           }
        }
        int finalmax=-1;
        for(auto it:mp){
           if(it.second.size()==2){
            int num1=it.second[0];
            int num2=it.second[1];
            finalmax=max(finalmax,num1+num2);
           }
        }
        return finalmax;
    }
};