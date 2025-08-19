class Solution {
public:
    int dom = -1, dcnt = 0;
    vector<int> pfx;

    bool validSplit(int i, vector<int>& nums, bool both=false) {
        int n = nums.size();
        int n1 = i+1, n2 = n-n1;;
        int c1 = pfx[i], c2 = dcnt - c1;
        return (c1 > (n1/2)) && (c2 > (n2/2));
    }

    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        // find the dom
        unordered_map<int, int> cnt;
        for(auto el: nums) cnt[el]++;
        for(auto el: cnt) if(el.second > dcnt) dom = el.first, dcnt = el.second;
        // fill pfx
        pfx.push_back(nums[0] == dom);
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] == dom) pfx.push_back(pfx[i-1] + 1);
            else pfx.push_back(pfx[i-1]);
        }
        // lin search
        int ans = -1;
        for(int i = 0 ; i < n ; i++) if(validSplit(i, nums, true)) return i;
        return -1;
    }
};
