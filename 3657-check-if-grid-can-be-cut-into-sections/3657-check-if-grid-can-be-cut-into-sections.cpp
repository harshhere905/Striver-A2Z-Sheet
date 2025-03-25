class Solution {
public:
    void merge_intervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return;
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        
        for (auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] <= interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        intervals = merged;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_axis, y_axis;
        
        for (auto& rect : rectangles) {
            x_axis.push_back({rect[0], rect[2]});
            y_axis.push_back({rect[1], rect[3]});
        }
        
        merge_intervals(x_axis);
        merge_intervals(y_axis);

        return (x_axis.size() >= 3 || y_axis.size() >= 3);
    }
};
