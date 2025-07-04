class Solution {
public:
    pair<string, vector<int>> process(string w) {
        string a; vector<int> b;
        char ca = '!';
        int j = -1;
        for(int i = 0 ; i < w.length() ; i++) {
            if(w[i] == ca) b[j]++;
            else {
                a += w[i];
                b.push_back(1);
                ca = w[i];
                j++;
            }
        }
        return {a, b};
    }
    
    bool isit(string A, string B) {
        auto AA = process(A);
        auto BB = process(B);
        if(AA.first != BB.first) return false;
        for(int i = 0 ; i < AA.second.size() ; i++) {
            int one = AA.second[i], two = BB.second[i];
            if(one < two) return false;
            if(one >= 3) continue;
            if(one != two) return false;
        }
        return true;
    }
    
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for(auto w: words) ans += isit(s, w);
        return ans;
    }
};
