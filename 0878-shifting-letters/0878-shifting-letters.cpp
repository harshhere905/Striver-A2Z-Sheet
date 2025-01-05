class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int n=s.size();
        string res=s;
        vector<long long int>cumulative(n);
        cumulative[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            cumulative[i]=cumulative[i+1]+shifts[i];
        }
        for(long long int i=0;i<n;i++){
            res[i] = (s[i] - 'a' + cumulative[i] + 26) % 26 + 'a';
        }
        return res;
    }
};