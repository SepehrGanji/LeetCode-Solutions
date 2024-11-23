class Solution {
public:
    long long cost(char from, char to, vector<int>& nextCost, vector<int>& previousCost) {
        int fromIndex = from - 'a';
        int toIndex = to - 'a';
        int forwardSteps = (toIndex >= fromIndex) ? (toIndex - fromIndex) : (26 - (fromIndex - toIndex));
        long long forwardCost = 0;
        for (int i = 0 ; i < forwardSteps ; i++) {
            forwardCost += nextCost[(fromIndex + i) % 26];
        }
        int backSteps = (fromIndex >= toIndex) ? (fromIndex - toIndex) : (26 - (toIndex - fromIndex));
        long long backCost = 0;
        for (int i = 0 ; i < backSteps ; ++i) {
            backCost += previousCost[(fromIndex - i + 26) % 26];
        }
        return min(forwardCost, backCost);
    }

    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        for(int i = 0 ; i < s.length(); i++) {
            int sc = s[i], tc = t[i];
            ans += cost(sc, tc, nextCost, previousCost);
        }
        return ans;
    }
};
