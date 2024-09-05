class Solution {
public:
    string convert(string s, int numRows) {
    if(numRows == 1) return s;
    int n = s.length();
    char arr[numRows][n];
    for(int i = 0 ; i < numRows ; i++) 
        for(int j = 0 ; j < n ; j++) arr[i][j] = '\t';
    int p = 0;
    bool zig = true;
    int i = 0, j = 0;
    while(p < n) {
        arr[i][j] = s[p++];
        if(zig) {
            i++;
            if(i >= numRows) {
                zig = false;
                i--; i--;
                j++;
            }
        } else {
            i--; j++;
            if(i <= -1) {
                zig = true;
                i++; j--;
                i++;
            }
        }
    }
    string ans = "";
    for(int i = 0 ; i < numRows ; i++) 
        for(int j = 0 ; j < n ; j++) if(arr[i][j] != '\t') ans += arr[i][j];

    return ans;
}
};
