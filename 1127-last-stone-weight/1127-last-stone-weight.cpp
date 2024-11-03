class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>max(stones.begin(),stones.end());
        while(max.size()>1){
            int first=max.top();
            max.pop();
            int second=max.top();
            max.pop();
            if(first!=second){
                max.push(first-second);
            }
        }
        return max.empty()?0:max.top();
    }
};