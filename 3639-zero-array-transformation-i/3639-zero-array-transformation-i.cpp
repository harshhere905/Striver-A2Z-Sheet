class Solution {
public:
    int n;
    int q;
    bool check(vector<int>& nums, vector<vector<int>>& queries,int mid){
        vector<int>diff(n,0);
        for(int i=0;i<=mid;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int x=1;
            diff[l]+=x;
            if(r+1<n){
                diff[r+1]-=x;
            }
        }
            int curr_sum=0;
            for(int i=0;i<nums.size();i++){
                curr_sum+=diff[i];
                diff[i]=curr_sum;
                if(nums[i]-diff[i]>0){
                    return false;
                }
            }
        return true;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        q=queries.size();
        auto lambda=[](int x){
            return x==0;
        };
        if(all_of(nums.begin(),nums.end(),lambda)){
            return true;
        }
        int low=0;
        int high=queries.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,queries,mid)==true){
                return true;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};