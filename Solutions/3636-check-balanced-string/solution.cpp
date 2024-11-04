class Solution {
public:
    bool isBalanced(string num) {
        int odd = 0, even = 0;
        int n = num.length();
        for(int i = 0 ; i < n ; i += 2) even += (num[i] - '0');
        for(int i = 1 ; i < n ; i += 2) odd += (num[i] - '0');
        return even == odd;
    }
};
