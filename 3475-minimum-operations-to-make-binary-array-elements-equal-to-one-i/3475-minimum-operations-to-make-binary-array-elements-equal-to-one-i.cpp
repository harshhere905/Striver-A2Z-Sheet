class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int flips=0;
        int flipcount=0;
        vector<bool>check(n,false);
        for(int i=0;i<n;i++){
            if(i>=3 && check[i-3]==true){
                flipcount--;
            }
            if(flipcount%2==nums[i]){
                if(i+3>n){
                    return -1;
                }
                flips++;
                flipcount++;
                check[i]=true;
            }
        }
        return flips;
    }
};