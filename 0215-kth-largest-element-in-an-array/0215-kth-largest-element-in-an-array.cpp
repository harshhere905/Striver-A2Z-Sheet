class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        int temp=k-1;
        while(temp!=0){
            pq.pop();
            temp--;
        }
        return pq.top();
    }
};