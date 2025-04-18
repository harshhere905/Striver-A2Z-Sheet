class Solution {
public:
    string countAndSay(int n) {
        queue<int>qp;
        qp.push(1);
        int cnt=1;
        int fro=0;
        while(n-1){
            qp.push(-1);
            while(qp.front()!=-1){
                fro=qp.front();
                qp.pop();
                cnt=1;
            while(!qp.empty()&&qp.front()==fro){
                cnt++;
                qp.pop();
            }
            qp.push(cnt);
            qp.push(fro);
            }
            qp.pop();
            n--;
        }
        string ans="";
        while(!qp.empty()){
           int num=qp.front();
           qp.pop();
           ans+=to_string(num);
        }
        return ans;
    }
};