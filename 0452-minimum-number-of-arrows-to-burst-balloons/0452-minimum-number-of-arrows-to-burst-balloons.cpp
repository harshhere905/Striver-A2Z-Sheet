class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       auto lambda=[](const vector<int>& a, const vector<int>& b){
         return a[1]<b[1];
       };
       sort(points.begin(),points.end(),lambda);
       int n=points.size();
       int i=0;
       int j=1;
       int ans=1;
       while(j<n){
           vector<int>curr_int=points[i];
           vector<int>next_int=points[j];
            //int cs=curr_int[0];
            int ce=curr_int[1];
            int ns=next_int[0];
            //int ne=next_int[1];
            if(ce<ns){
                ans++;
                i=j;j++;
            }
            else if(ce>=ns){
                j++;
            }
       }
       return ans;
    }
};