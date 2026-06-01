class Solution {
public:
    int minimumCost(vector<int>& cost) {
        priority_queue<int> pq(cost.begin(), cost.end());
        int ans = 0;
        while (!pq.empty()) {
            int n = 2;
            while (n-- && !pq.empty()) {
                ans += pq.top();
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
            }
        }
        return ans;
    }
};