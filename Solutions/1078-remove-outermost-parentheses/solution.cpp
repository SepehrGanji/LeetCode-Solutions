class Solution {
public:
    // string del(string s) {}
    
    string removeOuterParentheses(string s) {
        vector<string> prims;
        stack<char> qu;
        int idx = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            int ch = s[i];
            if(ch == '(') qu.push('(');
            else {
                qu.pop();
                if(qu.empty()) {
                    string yay = "";
                    for(int ii = idx + 1 ; ii < i ; ii++) yay += s[ii];
                    prims.push_back(yay);
                    idx = i+1;
                }
            }
        }
        
        string ans = "";
        for(auto prim: prims) {
            ans += prim;
        }
        return ans;
    }
};
