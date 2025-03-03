class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int>lower,greater,equal;
       for(int n:nums){
        if(n<pivot){
            lower.push_back(n);
        }
        else if(n>pivot){
            greater.push_back(n);
        }
        else{
            equal.push_back(n);
        }
       }
       lower.insert(lower.end(),equal.begin(),equal.end());
       lower.insert(lower.end(),greater.begin(),greater.end());
       return lower;
    }
};