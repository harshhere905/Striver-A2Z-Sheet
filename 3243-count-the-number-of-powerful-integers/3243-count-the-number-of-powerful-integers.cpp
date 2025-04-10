class Solution {
public:
    long long solve(string& startstr,string& s, int limit){
        if(startstr.length()<s.length()){
            return 0;
        }
        long long count=0;
        string suffix_len=startstr.substr(startstr.length()-s.length());
        int rem_len=startstr.length()-s.length();
        for(int i=0;i<rem_len;i++){
            int digit=startstr[i]-'0';
            if(digit<=limit){
                count+=digit*pow(limit+1,rem_len-i-1);
            }
            else{
                count+=pow(limit+1,rem_len-i);
                return count;
            }

        }
        if(suffix_len>=s){
            count++;
        }
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startstr=to_string(start-1);
        string finishstr=to_string(finish);
        return solve(finishstr,s,limit)-solve(startstr,s,limit);
    }
};