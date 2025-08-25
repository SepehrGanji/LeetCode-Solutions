class Solution {
public:
    void trimTrailingSpaces(std::string& s) {
        size_t last_non_space = s.find_last_not_of(" \t\n\r\f\v"); 
        if (last_non_space != std::string::npos) {
            s.erase(last_non_space + 1);
        } else {
            s.clear();
        }
    }

    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        vector<vector<char>> arr(rows, vector<char>(cols, ' '));
        int ptr = 0;
        for(int i = 0 ; i < rows ; i++)
            for(int j = 0 ; j < cols ; j++)
                arr[i][j] = encodedText[ptr++];
        
        string ans = "";
        for(int off = 0 ; off < cols ; off++) {
            for(int i = 0 ; i < rows ; i++) {
                int j = i + off;
                if(j >= cols) break;
                ans += arr[i][j];
            }
        }
        trimTrailingSpaces(ans);
        return ans;
    }
};
