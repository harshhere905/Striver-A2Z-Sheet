class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt=0;
        bool swapped=true;        
        while(swapped){
            swapped=false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i]=='0'&&s[i+1]=='1') {
                    swap(s[i],s[i+1]);
                    i++;
                    swapped=true;
                }
            }
            if(swapped) cnt++;
        }
        return cnt;
    }
};