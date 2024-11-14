class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long ans = 0;
        sort(maximumHeight.begin(), maximumHeight.end());
        int last_h_ass = 1e9+10;
        for(int i = maximumHeight.size()-1 ; i >= 0 ; i--) {
            int el = maximumHeight[i];
            if(el >= last_h_ass) {
                el = last_h_ass-1;
                if(el <= 0) return -1;
            }
            //cout << "i: " << i << "&& el: " << el << endl;
            ans += el;
            last_h_ass = el;
        }
        return ans;
    }
};
