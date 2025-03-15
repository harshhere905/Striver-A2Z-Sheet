class Spreadsheet {
public:
    vector<vector<int>> mat;
    Spreadsheet(int rows) {
       mat.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value){
        mat[stoi(cell.substr(1))-1][cell[0]-'A']=value;
    }
    
    void resetCell(string cell) {
        mat[stoi(cell.substr(1))-1][cell[0]-'A']=0; 
    }
    
    int getValue(string formula) {
        int sum=0;
        int i=0;
        while(i!=formula.size()){
            if(isalpha(formula[i])){
               int col = formula[i] - 'A';
               i++;
               string rowStr = "";
                while (i < formula.size() && isdigit(formula[i])) {
                    rowStr += formula[i];
                    i++;
                }
                int row = stoi(rowStr) - 1;
                sum += mat[row][col];
            }
            else if(isdigit(formula[i])){
               int num=0;
               while(i<formula.size()&&isdigit(formula[i])){
                  num=num*10+(formula[i]-'0');
                  i++;
               }
               sum+=num;
            }
            else{
                i++;
            }
            
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */