class Solution {
public:
    bool canDo(vector<int>& citations, int ans) {
        int n = citations.size();
        int l = 0, r = citations.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if(citations[mid] < ans) l = mid+1;
            else r = mid;
        }
        if(r == n) return false;
        return n-r >= ans;
    }

    int hIndex(vector<int>& citations) {
        int l = 0, r = 1000;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(canDo(citations, mid)) l = mid + 1;
            else r = mid - 1;
        }
        return l-1;
    }
};
