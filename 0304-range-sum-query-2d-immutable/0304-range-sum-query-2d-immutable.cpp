class NumMatrix {
public:
    vector<vector<int>> arr;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        arr = vector<vector<int>>(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += matrix[i][j];
                arr[i][j] = sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = 0;
        for(int i = row1; i <= row2; i++) {
            if(col1 > 0)
                total += arr[i][col2] - arr[i][col1 - 1];
            else
                total += arr[i][col2];
        }
        return total;
    }
};
