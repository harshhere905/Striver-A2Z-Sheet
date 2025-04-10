class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>ans;
        unordered_set<int>seen;
        for(int i=1;i<=bound;i*=x){
            for(int j=1;j<=bound;j*=y){
                int sum=i+j;
                if(sum<=bound && seen.find(sum)==seen.end()){
                    ans.push_back(sum);
                    seen.insert(sum);
                }
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return ans; 
    }
};