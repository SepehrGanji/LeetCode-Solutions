class Solution {
public:
    stack<string> ans;

    void procees(string s) {
        if(s == "" || s == ".") return;
        if(s == "..") {
            if(!ans.empty()) ans.pop();
            return;
        }
        ans.push(s);
    }

    string simplifyPath(string path) {
        int ptr = 0;
        int n = path.length();
        string curr = "";
        while(ptr < n) {
            if(path[ptr] == '/') {
                procees(curr);
                curr = "";
            } else {
                curr += path[ptr];
            }
            ptr++;
        }
        procees(curr);
        if(ans.empty()) return "/";
        string ansans = "";
        stack<string> ans2;
        while(!ans.empty()) {
            ans2.push(ans.top()); ans.pop();
        }
        while(!ans2.empty()) {
            ansans += "/";
            ansans += ans2.top(); ans2.pop(); 
        }
        return ansans;
    }
};
