class Solution {
public:
    bool poss(vector<int>& nums, int op, double pen) {
        for(auto el: nums) {
            if(el <= pen) continue;
            op -= ceil(el / pen);
            op++;
        }
        return op >= 0;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9+1;
        while(l < r) {
            int mid = (l+r)/2;
            if(poss(nums, maxOperations, mid)) {
                r = mid;
            } else l = mid+1;
        }
        return r;
    }
};
