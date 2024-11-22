class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int c = 1;
        for(int i = digits.size()-1 ; i >= 0 ; i--) {
            int res = digits[i] + c;
            ans.push_back(res%10);
            c = res/10;
        }
        if(c > 0) ans.push_back(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
