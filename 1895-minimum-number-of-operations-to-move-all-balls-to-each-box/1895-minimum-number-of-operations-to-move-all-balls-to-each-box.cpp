class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>res;
        vector<int>pos;
        for(int i=0;i<boxes.size();i++){
           if(boxes[i]=='1'){
            pos.push_back(i);
           }
        }
        for(int i=0;i<boxes.size();i++){
            int sum=0;
            for(int it:pos){
                sum+=abs(i-it);
            }
            res.push_back(sum);
        }
        return res;
    }
};
