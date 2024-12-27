class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        priority_queue<int>qp;
        qp.push(values[0]);
        int finalans=INT_MIN;
        for(int j=1;j<n;j++){
            int queue_top=qp.top();
            int diff=values[j]-j;
            int finalmax=queue_top+diff;
            finalans=max(finalans,finalmax);
            int temp=values[j]+j;
            qp.push(temp);
        }
        return finalans;
    }
};