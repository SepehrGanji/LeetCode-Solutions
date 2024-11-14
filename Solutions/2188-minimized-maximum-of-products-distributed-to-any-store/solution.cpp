class Solution {
public:
    bool feas(int n, vector<int> quantities, int ans) {
        int ptr = 0;
        int m = quantities.size();
        for(int i = 0 ; i < n ; i++) {
            if(ptr >= m) return true;
            if(quantities[ptr] <= ans) {
                ptr++;
            } else {
                quantities[ptr] -= ans;
            }
        }
        if(ptr < m) return false;
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0, r = 1e5 + 10;
        sort(quantities.begin(), quantities.end());
        while(l < r) {
            int mid = ceil((l+r)/2.0);
            bool fisbo = feas(n, quantities, mid);
            //cout << mid << ':' << fisbo << endl;
            if(fisbo) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        return r+1;
    }
};
