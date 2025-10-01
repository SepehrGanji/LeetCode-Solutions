class Solution {
public:
    int finall = -1;
    vector<string> findStrobogrammatic(int n) {
        if(finall == -1) finall = n;
        if(n == 0) {
            return { "" };
        }
        if(n == 1) {
            vector<string> ans = {"0", "1", "8"};
            return ans;
        }
        vector<string> ans;
        vector<string> lans = findStrobogrammatic(n-2);
        vector<pair<string, string>> pairs = {
            {"1", "1"},
            {"6", "9"},
            {"9", "6"},
            {"8", "8"},
            {"0", "0"}
        };
        for(auto p: pairs) {
            for(auto el: lans) {
                if(p.first != "0" || n != finall)
                    ans.push_back(p.first + el + p.second);
            }
        }
        return ans;
    }
};
