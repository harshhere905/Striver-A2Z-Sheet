class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1, 0); // Extra index to handle boundary
        
        for (auto& b : bookings) {
            res[b[0] - 1] += b[2]; // Add seats at start index
            res[b[1]] -= b[2];     // Remove seats after end index
        }
        
        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1]; // Convert difference array to prefix sum
        }
        
        res.pop_back(); // Remove extra index
        return res;
    }
};
