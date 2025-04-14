class Solution {
public:
    bool isStrobogrammatic(string num) {
        string sec = "";
        for(auto dig: num) {
            if(dig == '2' || dig == '3' || dig == '4' || dig == '5' || dig == '7') return false;
            if(dig == '6') {
                sec = '9' + sec;
            } else if(dig == '9') {
                sec = '6' + sec;
            } else {
                sec = dig + sec;
            }
            
        }
        return sec == num;
    }
};
