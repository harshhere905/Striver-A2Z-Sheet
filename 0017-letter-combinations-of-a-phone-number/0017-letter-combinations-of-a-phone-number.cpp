class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<string,string>mp;
        char ch='a';
        for(int i=2;i<=9;i++){
            int t=3;
            if(i==7 || i==9){
                t++;
            }
            while(t--){
               mp[to_string(i)]+=ch;
               ch++;
            }
        }
        int len=digits.length();
        vector<string>ans;
        if(len==0){
            return ans;
        }
        if(len==1){
           string temp=mp[string(1, digits[0])];
           for(int i=0;i<temp.size();i++){
               ans.push_back(string(1, temp[i]));
           }
           return ans;
        }
        else if(len==2){
            string temp1=mp[string(1, digits[0])];
            string temp2=mp[string(1, digits[1])];
            for(int i=0;i<temp1.size();i++){
                for(int j=0;j<temp2.size();j++){
                    ans.push_back(string(1,temp1[i])+temp2[j]);
                }
            }
        }
        else if(len==3){
            string temp1=mp[string(1, digits[0])];
            string temp2=mp[string(1, digits[1])];
            string temp3=mp[string(1, digits[2])];
            for(int i=0;i<temp1.size();i++){
                for(int j=0;j<temp2.size();j++){
                    for(int k=0;k<temp3.size();k++){
                        ans.push_back(string(1,temp1[i])+temp2[j]+temp3[k]);
                    }
                }
            }
        }
        else{
            string temp1=mp[string(1, digits[0])];
            string temp2=mp[string(1, digits[1])];
            string temp3=mp[string(1, digits[2])];
            string temp4=mp[string(1, digits[3])];
            for(int i=0;i<temp1.size();i++){
                for(int j=0;j<temp2.size();j++){
                    for(int k=0;k<temp3.size();k++){
                        for(int l=0;l<temp4.size();l++){
                            ans.push_back(string(1,temp1[i])+temp2[j]+temp3[k]+temp4[l]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
