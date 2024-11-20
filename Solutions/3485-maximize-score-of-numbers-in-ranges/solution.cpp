class Solution {
public:
    bool feas(vector<int>& start, int d, long long mid) {
        //cout << "Feas of: " << start[0] << ',' << d << ',' << mid << endl;
        long long last_ass = start[0];
        for(int i = 1 ; i < start.size() ; i++) {
            long long el = start[i];
            if(last_ass + mid > el + d) return false;
            last_ass = max(el, last_ass + mid);
        }
        //cout << "=> TRUE" << endl;
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long l = 0, r = 2000000001;
        while(l < r) {
            long long mid = (l+r)/2;
            if(feas(start, d, mid)) l=mid+1;
            else r=mid;
        }
        return l-1;
    }
};
