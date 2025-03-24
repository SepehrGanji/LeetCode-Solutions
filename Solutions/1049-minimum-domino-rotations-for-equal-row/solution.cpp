class Solution {
public:
    int cost(vector<int>& arr, int target) {
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++) {
            if(arr[i] != target) ans++;
        }
        return ans;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int pos1 = -1, pos2 = -1;
        if(tops[0] == bottoms[0]) pos1 = tops[0];
        else {
            pos1 = min(tops[0], bottoms[0]);
            pos2 = max(tops[0], bottoms[0]);
        }
        for(int i = 1 ; i < n ; i++) {
            int t = tops[i], b = bottoms[i];
            if(t != pos1 && b != pos1) pos1 = -1;
            if(t != pos2 && b != pos2) pos2 = -1;
        }
        if(pos1 == -1 && pos2 == -1) return -1;
        int ans = n+10;
        if(pos1 != -1) {
            ans = min(ans, cost(tops, pos1));
            ans = min(ans, cost(bottoms, pos1));
        }
        if(pos2 != -1) {
            ans = min(ans, cost(tops, pos2));
            ans = min(ans, cost(bottoms, pos2));
        }
        return ans;
    }
};
