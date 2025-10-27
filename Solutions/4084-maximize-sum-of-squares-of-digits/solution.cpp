class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9) return "";
        string ans = "";
        while(num--) {
            int dig = min(sum, 9);
            sum -= dig;
            ans += ('0' + dig);
        }
        return ans;
    }
};
