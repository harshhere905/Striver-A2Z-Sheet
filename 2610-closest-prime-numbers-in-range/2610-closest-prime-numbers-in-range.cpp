class Solution {
public:
    int is_prime(int n){
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>sample;
        for(int i=left;i<=right;i++){
            if(is_prime(i)){
                sample.push_back(i);
            }
        }
        if(sample.size()<2){
            return {-1,-1};
        }
        vector<int>ans = {-1,-1};
        int min_gap=INT_MAX;
        for(int i=1;i<sample.size();i++){
            int gap=sample[i]-sample[i-1];
            if(gap<min_gap){
                min_gap=gap;
                ans={sample[i-1],sample[i]};
            }
        }
        return ans;
    }
};
