class Solution {
public:
    struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int k = 0, x = 0, y = 0;
    int ans=0;
    unordered_set<pair<int,int>, hash_pair> st;

    for(auto &it : obstacles){
        st.insert({it[0], it[1]}); 
    }
        for(auto it:commands){
            if(it==-1){
                k+=90;
                if(k==360){
                    k=0;
                }
            }
            else if(it==-2){
                if(k==0){
                    k=270;
                    continue;
                }
                k-=90;
            }
            else if(it>0 && k==0){
                for(int i=1;i<=it;i++){
                    y+=1;
                    if(st.find({x,y})!=st.end()){
                        y--;
                        break;
                    }
                }
            }
            else if(it>0 && k==90){
                for(int i=1;i<=it;i++){
                    x+=1;
                    if(st.find({x,y})!=st.end()){
                        x--;
                        break;
                    }
                }
            }
            else if(it>0 && k==180){
                for(int i=1;i<=it;i++){
                    y-=1;
                    if(st.find({x,y})!=st.end()){
                        y++;
                        break;
                    }
                }
            }
            else{
                for(int i=1;i<=it;i++){
                    x-=1;
                    if(st.find({x,y})!=st.end()){
                        x++;
                        break;
                    }
                }
            }
            ans=max(ans,(x*x)+(y*y));
        }
        return ans;
    }
};