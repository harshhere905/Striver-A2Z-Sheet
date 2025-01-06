class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>res;
        for(int i=0;i<boxes.size();i++){
            int cnt=0;
           for(int j=0;j<i;j++){
             if(boxes[j]=='1'){
                cnt+=i-j;     
             }
           }
           for(int k=i+1;k<boxes.size();k++){
             if(boxes[k]=='1'){
                cnt+=k-i;
             }
           }
        res.push_back(cnt);
        }
        return res;
    }
};
