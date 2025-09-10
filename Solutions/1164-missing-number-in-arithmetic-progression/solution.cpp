class Solution {
public:
    int missingNumber(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for(int i = 0 ; i < n-1 ; i++) {
            int diff = arr[i+1] - arr[i];
            mp[diff]++;
        }

        for(int i = 0 ; i < n-1 ; i++) {
            int diff = arr[i+1] - arr[i];
            if(mp[diff] == 1 && mp[diff/2] >= 1) {
                return arr[i] + diff/2;
            }
        }
        return arr[0];
    }
};

