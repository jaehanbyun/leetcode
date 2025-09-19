class Spreadsheet {
public:
    Spreadsheet(int rows) : sheet(rows, vector<int>(26, 0)) {}
    
    void setCell(string cell, int value) {
        int c = cell[0] - 'A';                 
        int r = stoi(cell.substr(1)) - 1;       
        this->sheet[r][c] = value;  
    }
    
    void resetCell(string cell) {
        int c = cell[0] - 'A';                 
        int r = stoi(cell.substr(1)) - 1;       
        this->sheet[r][c] = 0;  
    }
    
    int getValue(string formula) {
        size_t eq = formula.find('=');
        size_t plus = formula.find('+');
        string lhs = formula.substr(eq + 1, plus - (eq + 1));
        string rhs = formula.substr(plus + 1);

        auto evalOperand = [&](const string& s) -> int {
            if (!s.empty() && isupper(s[0])) {
                int c = s[0] - 'A';
                int r = stoi(s.substr(1)) - 1;
                return sheet[r][c]; 
            } else {
                return stoi(s);     
            }
        };

        return evalOperand(lhs) + evalOperand(rhs);
    }

private:
    vector<vector<int>> sheet;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */