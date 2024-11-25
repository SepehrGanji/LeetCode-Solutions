class Solution {
public:
    vector<string> ans;

    void solve(int op, int cl, string s, int n) {
        if(op == cl && op + cl == n * 2) {
            ans.push_back(s);
            return;
        }
        if(op < n) {
            solve(op+1, cl, s + "(", n);
        }
        if(cl < op) {
            solve(op, cl+1, s + ")", n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        solve(0, 0, "", n);
        return ans;    
    }
};
