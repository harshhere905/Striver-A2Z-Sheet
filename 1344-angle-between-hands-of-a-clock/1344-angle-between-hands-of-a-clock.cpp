class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle=abs(30*hour-5.5*minutes);
        double ans=min(angle,360-angle);
        return ans;
    }
};