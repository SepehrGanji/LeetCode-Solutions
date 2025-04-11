class Solution {
public:
    bool isSem(int num) {
        vector<int> arr;
        while(num > 0) {
            arr.push_back(num % 10);
            num /= 10;
        }
        int n = arr.size();
        if(n % 2 == 1) return false;
        int mmd = 0;
        for(int i = 0 ; i < n / 2 ; i++) mmd += arr[i];
        for(int i = n / 2 ; i < n ; i++) mmd -= arr[i];
        return mmd == 0;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low ; i <= high ; i++) ans += isSem(i);
        return ans;    
    }
};
