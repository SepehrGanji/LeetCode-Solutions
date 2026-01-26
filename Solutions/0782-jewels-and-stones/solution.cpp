class Solution {
public:
    bool isIt(string jewels, char a) {
        for(auto ch: jewels) {
            if(a == ch) return true;
        }
        return false;
    }

    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(auto ch: stones) if(isIt(jewels, ch)) ans++;
        return ans;
    }
};
