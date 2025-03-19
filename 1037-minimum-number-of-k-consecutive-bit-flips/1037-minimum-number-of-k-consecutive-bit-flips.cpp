class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flips=0;
        int flipcount=0;
        vector<bool>check(n,false);
        for(int i=0;i<n;i++){
            if(i>=k && check[i-k]==true){
                flipcount--;
            }
            if(flipcount%2==nums[i]){
                if(i+k>n){
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