class Spreadsheet {
private:
    vector<vector<int>> arr;
    int n;
    int s2num(string s) {
        int n = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            int dig = s[i] - '0';
            n *= 10;
            n += dig;
        }
        return n;
    }
    void cellconv(int &col, int &row, string cell) {
        col = cell[0] - 'A';
        string mmd = cell.substr(1);
        row = s2num(mmd);
    }

public:
    Spreadsheet(int rows) {
        n = rows+1;
        arr.resize(26);
        for(int i = 0 ; i < 26 ; i++)
            for(int j = 0 ; j < n ; j++) arr[i].push_back(0);
    }
    
    void setCell(string cell, int value) {
        int col, row;
        cellconv(col, row, cell);
        arr[col][row] = value;
    }
    
    void resetCell(string cell) {
        int col, row;
        cellconv(col, row, cell);
        arr[col][row] = 0;
    }
    
    int getValue(string formula) {
        string fm = formula.substr(1);
        int pos = fm.find("+");
        string one = fm.substr(0, pos);
        string two = fm.substr(pos+1);
        int onenum = 0, twonum = 0;
        if(one[0] >= 'A' && one[0] <= 'Z') {
            int c, r;
            cellconv(c, r, one);
            onenum = arr[c][r];
        } else {
            onenum = s2num(one);
        }
        if(two[0] >= 'A' && two[0] <= 'Z') {
            int c, r;
            cellconv(c, r, two);
            twonum = arr[c][r];
        } else {
            twonum = s2num(two);
        }
        return onenum+twonum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
