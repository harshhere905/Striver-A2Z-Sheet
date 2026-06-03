class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                int result;
                if (landStartTime[i] >= waterStartTime[j]) {
                    int waterFinish = waterStartTime[j] + waterDuration[j];
                    int landActualStart = max(waterFinish, landStartTime[i]);
                    result = landActualStart + landDuration[i];
                } else {
                    int landFinish = landStartTime[i] + landDuration[i];
                    int waterActualStart = max(landFinish, waterStartTime[j]);
                    result = waterActualStart + waterDuration[j];
                }
                ans = min(ans, result);
            }
        }
        return ans;
    }
};