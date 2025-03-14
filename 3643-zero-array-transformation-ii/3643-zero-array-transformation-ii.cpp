class Solution {
public:
    int n;
    int Q;
    bool check(vector<int>nums,vector<vector<int>>queries,int mid){
           vector<int>diff(n,0);
           for(int i=0;i<=mid;i++){
              int l=queries[i][0];
              int r=queries[i][1];
              int x=queries[i][2];
              diff[l]+=x;
              if(r+1<n){
                diff[r+1]-=x;
              }
           }
           int curr_sum=0;
           for(int i=0;i<n;i++){
            curr_sum+=diff[i];
            diff[i]=curr_sum;
            if(nums[i]-diff[i]>0){
                return false;
            }
           }
           return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        Q=queries.size();
        auto lambda= [](int x){
            return x==0;
        };
        if(all_of(nums.begin(),nums.end(),lambda)){
            return 0;
        }
        int l=0;
        int r=Q-1;
        int k=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,queries,mid)==true){
                k=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return k;
    }
};