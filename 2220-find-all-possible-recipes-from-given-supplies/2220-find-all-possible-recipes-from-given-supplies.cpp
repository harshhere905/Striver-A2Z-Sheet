class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string>st;
        for(int i=0;i<supplies.size();i++){
            st.insert(supplies[i]);
        }
        bool temp=true;
        vector<string>res;
        while(temp){
        temp=false;
        for(int i=0;i<recipes.size();i++){
            if (st.find(recipes[i]) != st.end()) continue;
            bool check=true;
           for(int j=0;j<ingredients[i].size();j++){
               if(st.find(ingredients[i][j])==st.end()){
                  check=false;
                  break;
               }
           }
           if(check){
              st.insert(recipes[i]);
              res.push_back(recipes[i]);
              temp=true;
           }
        }
        }
        
        return res;
    }
};