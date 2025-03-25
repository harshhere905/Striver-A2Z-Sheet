class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string ce=event1[1];
        string cs=event1[0];
        string ne=event2[1];
        string ns=event2[0];
        if(ce>=ns){
            if(ne<cs){
            return false;
            }
            return true;
        }
        return false;
    }
};