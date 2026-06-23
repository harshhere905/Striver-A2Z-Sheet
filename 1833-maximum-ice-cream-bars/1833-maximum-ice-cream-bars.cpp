class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int ans=0;
        for(auto it:costs){
            if(it<=coins){
                coins-=it;
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};