class Solution {
public:
    string bin(int a) {
        string ans = "";
        while(a > 0) {
            if(a % 2 == 0) {
                ans = '0' + ans;
            } else {
                ans = '1' + ans;
            }
            a /= 2;
        }
        return ans;
    }

    string convertDateToBinary(string date) {
        string year = "";
        year += date[0];
        year += date[1];
        year += date[2];
        year += date[3];
        string month = "";
        month += date[5];
        month += date[6];
        string day = "";
        day += date[8];
        day += date[9];
        string ans = "";
        ans = bin(stoi(year)) + '-' + bin(stoi(month)) + '-' + bin(stoi(day));
        return ans;
    }
};
