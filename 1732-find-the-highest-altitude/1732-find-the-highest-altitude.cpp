class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude=0;
        int ans=0;
        for(auto it:gain){
            altitude+=it;
            ans=max(ans,altitude);
        }
        return ans;
    }
};