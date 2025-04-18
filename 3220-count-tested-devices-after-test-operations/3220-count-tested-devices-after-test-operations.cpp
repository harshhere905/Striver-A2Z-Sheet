class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int test=0;
        for(int n:batteryPercentages){
            if(n-test>0){
                test++;
            }
        }
    return test;
    }
};