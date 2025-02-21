using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; i++)
            pq.push({matrix[i][0], i, 0}); 
        while (--k) {
            vector<int> top = pq.top(); 
            pq.pop();
            int val = top[0], row = top[1], col = top[2];
            if (col + 1 < n) 
                pq.push({matrix[row][col + 1], row, col + 1});
        }
        return pq.top()[0];
    }
};
