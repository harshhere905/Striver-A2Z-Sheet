class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int total_con=n*n;
        int cnt=0;
        int temp=0;
        int samp=1;
        while(temp<=maxWeight&&total_con!=0){
           temp+=samp*w;
           if(temp<=maxWeight){
           cnt++;
           total_con--;
           }
        }
        return cnt;
    }
};