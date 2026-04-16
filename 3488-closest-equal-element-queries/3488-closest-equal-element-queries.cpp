class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>result;
        for(auto it:queries){
            int target=nums[it];
            vector<int>& vec=mp[target];
            int sz=vec.size();
            if(sz==1){
                result.push_back(-1);
                continue;
            }
            int pos=lower_bound(vec.begin(),vec.end(),it)-vec.begin();
            int res=INT_MAX;
            //right
            int right=vec[(pos+1)%sz];
            int d=abs(it-right);
            res=min({res,d,n-d});

            //left
            int left=vec[(pos-1+sz)%sz];
            d=abs(it-left);
            res=min({res,d,n-d});
            
            result.push_back(res);
        }
        return result;
    }
};