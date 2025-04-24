class Solution {
public:
    vector<string> ans;
    
    void iter(int n, string so_far, int open, int close) {
        if(so_far.length() == 2*n) {
            ans.push_back(so_far);
            return;
        }
        // can we open
        if(open < n) iter(n, so_far+"(", open+1, close);
        // can we close
        if(close < open) iter(n, so_far+")", open, close+1);
    }
    
    vector<string> generateParenthesis(int n) {
        iter(n, "", 0, 0);
        return ans;
    }
};
