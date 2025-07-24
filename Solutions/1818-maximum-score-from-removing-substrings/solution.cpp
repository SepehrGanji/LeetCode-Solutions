class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x < y) {
            int tmp = x;
            x = y;
            y = tmp;
            reverse(s.begin(), s.end());
        }
        int ac = 0, bc = 0, ans = 0;
        for(auto ch: s) {
            if(ch == 'a') ac++;
            else if(ch == 'b') {
                if(ac > 0) {
                    ac--;
                    ans += x;
                } else bc++;
            } else {
                int mini = min(ac, bc);
                ans += y*mini;
                ac=0;
                bc=0;
            }
        }
        int mini = min(ac, bc);
        ans += y*mini;
        return ans;
    }
};
