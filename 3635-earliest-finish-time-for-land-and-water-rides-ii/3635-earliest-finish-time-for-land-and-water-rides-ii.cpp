class Solution {
public:
    long long solve(vector<int>& start1, vector<int>& dur1,
                    vector<int>& start2, vector<int>& dur2) {

        int m = start2.size();
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = 300005;
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
        vector<pair<int, int>> rides;
        for (int i = 0; i < m; i++) {
            rides.push_back({start2[i], dur2[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> s(m), d(m);
        for (int i = 0; i < m; i++) {
            s[i] = rides[i].first;
            d[i] = rides[i].second;
        }

        vector<long long> pref(m), suff(m);

        pref[0] = d[0];
        for (int i = 1; i < m; i++) {
            pref[i] = min(pref[i - 1], (long long)d[i]);
        }

        suff[m - 1] = (long long)s[m - 1] + d[m - 1];
        for (int i = m - 2; i >= 0; i--) {
            suff[i] = min(suff[i + 1], (long long)s[i] + d[i]);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < start1.size(); i++) {
            long long finish = (long long)start1[i] + dur1[i];

            int idx = upper_bound(s.begin(), s.end(), finish) - s.begin();

            if (idx > 0) {
                ans = min(ans, finish + pref[idx - 1]);
            }

            if (idx < m) {
                ans = min(ans, suff[idx]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans1 = solve(landStartTime, landDuration,
                               waterStartTime, waterDuration);

        long long ans2 = solve(waterStartTime, waterDuration,
                               landStartTime, landDuration);

        return min(ans1, ans2);
    }
};