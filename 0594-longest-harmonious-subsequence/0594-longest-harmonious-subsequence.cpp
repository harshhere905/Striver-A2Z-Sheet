class Solution {
public:
    int idx=-1;
    int firstocc(int& midy,vector<int>& temp){
        int index=-1;
        int l=0;
        int h=temp.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(temp[mid]==midy){
                h=mid-1;
                index=mid;
            }
            else if(temp[mid]>midy){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return index;
    }
    bool check(int& num,vector<int>& temp){
        int low=0;
        int high=temp.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(num-temp[mid]==1){
                idx=firstocc(temp[mid],temp);
                return true;
            }
            else if(num-temp[mid]>1){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
    int findLHS(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans=0;
       for(int j=nums.size()-1;j>=0;j--){
           if(check(nums[j],nums)){
              ans=max(ans,j-idx+1);
           }
       }
       return ans; 
    }
};