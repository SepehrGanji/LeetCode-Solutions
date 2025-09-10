class Solution {
public:
    bool valid(int mini, vector<int>& arr, int k) {
        k++;
        int cur = 0;
        for(auto el: arr) {
            cur += el;
            if(cur >= mini) {
                cur = 0;
                k--;
            }
        }
        return k <= 0;
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int su = 0;
        for(auto el: sweetness) su += el;
        int l = 0, r = su+1;
        while(l < r) {
            int mid = (l+r)/2;
            if(valid(mid, sweetness, k)) l = mid+1;
            else r = mid;
        }
        return l-1;
    }
};
