class Solution {
public:
    bool check(int num,unordered_map<int,int>& mp){
        unordered_map<int,int>temp;
        while(num){
            temp[num%10]++;
            num=num/10;
        }
        for(auto it:temp){
            if(it.second>mp[it.first]){
                return false;
            }
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;
        bool ch=false;
        for(int n:digits){
            if(n%2==0){
               ch=true;
            }
            mp[n]++;
        }
        if(!ch){
            return {};
        }
        vector<int>res;
        for(int i=100;i<=999;i++){
            if(i%2!=0){
                continue;
            }
            else{
                if(check(i,mp)){
                    res.push_back(i);
                }
            }
        }
    return res;
    }
};