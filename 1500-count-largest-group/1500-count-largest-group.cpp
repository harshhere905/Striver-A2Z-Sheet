class Solution {
public:
    int calculate(int num){
        int sum=0;
        while(num!=0){
           sum+=num%10;
           num=num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,vector<int>>mp;
        for(int i=1;i<=n;i++){
            int digit_sum=calculate(i);
            mp[digit_sum].push_back(i);
        }
        int max_size = 0, count = 0;
        for(auto& it : mp){
            if(it.second.size() > max_size){
                max_size = it.second.size();
                count = 1;
            } else if(it.second.size() == max_size){
                count++;
            }
        }
        return count;
    }
};