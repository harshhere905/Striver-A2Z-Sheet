class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(auto it:asteroids){
            if(it<=mass){
                if(mass>INT_MAX-it){
                    mass=INT_MAX;
                }
                else{
                  mass+=it;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};