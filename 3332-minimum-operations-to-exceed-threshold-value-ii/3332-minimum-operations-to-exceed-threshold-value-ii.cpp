class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minheap(nums.begin(), nums.end());
        int cnt = 0;
        while (minheap.top() < k) {
            if (minheap.size() < 2) break; 
            long long first = minheap.top(); minheap.pop();
            long long second = minheap.top(); minheap.pop();
           
            long long newElement = first * 2 + second;
            minheap.push(newElement);
            cnt++;
        }
        return cnt;
    }
};
