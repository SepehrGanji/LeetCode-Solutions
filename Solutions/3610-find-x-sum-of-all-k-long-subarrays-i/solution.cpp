class Solution {
public:
    int x_sum(vector<int> arr, int x) {
        map<int, int> mp;
        for(auto el: arr) mp[el]++;
        cout << "HI!" << endl;
        for(auto el: arr) {
            cout << el << ' ';
        }
        cout << endl;
        // if(mp.size() < x) {
        //     int su = 0;
        //     for(auto el: arr) su += el;
        //     return su;
        // }
        vector<pair<int, int>> mmd;
        for(auto el: mp) mmd.push_back({el.second, el.first});
        sort(mmd.begin(), mmd.end());
        int n = mmd.size();
        int i = n-1;
        int su = 0;
        while(x > 0 && i >= 0) {
            su += (mmd[i].first * mmd[i].second);
            i--;
            x--;
        }
        return su;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ; i < n-k+1 ; i++) {
            vector<int> arr;
            for(int j = i ; j < i + k ; j++) arr.push_back(nums[j]);
            ans.push_back(x_sum(arr, x));
        }
        return ans;
    }
};
