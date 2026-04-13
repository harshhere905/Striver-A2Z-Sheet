class Solution {
public:
    string reorderSpaces(string text) {
        int spaces=0;
        for(auto it:text){
            if(it==' '){
                spaces++;
            }
        }
        vector<string>words;
        string temp;
        bool check=false;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
               if(check){
                 words.push_back(temp);
                 temp="";
               }     
               check=false;           
               continue;
            }
            check=true;
            temp.push_back(text[i]);
        }
        if(check){
            words.push_back(temp);
        }
        string ans;
        int size=words.size();
        if (size == 1) { 
            return words[0] + string(spaces, ' ');
        }
        int required=(spaces/(size-1));
        int extra=(spaces%(size-1));
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            int t=required;
            if(i!=words.size()-1){
               while(t--){
                ans.push_back(' ');
               }
            }
        }
        while(extra--){
            ans.push_back(' ');
        }
        return ans;
    }
};