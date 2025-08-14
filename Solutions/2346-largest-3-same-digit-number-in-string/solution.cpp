class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.length();
        for(int i = 0 ; i < n - 2 ; i++) {
            if(num[i] == num[i+1] && num[i] == num[i+2]) {
                string local;
                local += num[i];
                local += num[i];
                local += num[i];
                ans = max(ans, local);
            }
        }
        return ans;
    }
};
