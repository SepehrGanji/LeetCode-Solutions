class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        int lst = -1;
        for(auto el: nums) {
            if(el == lst) continue;
            arr.push_back(el);
            lst = el;
        }
        int ans = 0;
        int n = arr.size();
        for(int i = 1 ; i < n - 1 ; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) ans++;
            if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) ans++;
        }
        return ans;
    }
};
