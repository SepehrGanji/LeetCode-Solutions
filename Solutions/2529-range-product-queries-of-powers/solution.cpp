class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> arr;
        while(n > 0) {
            int el = n & (-n);
            arr.push_back(el);
            n -= el;
        }
        sort(arr.begin(), arr.end());
        for(auto el: queries) {
            int l = el[0], r = el[1];
            long mmd = 1;
            for(int i = l ; i <= r ; i++) {
                mmd *= arr[i];
                mmd %= int(1e9+7);
            }
            ans.push_back(mmd);
        }
        return ans;
    }
};
