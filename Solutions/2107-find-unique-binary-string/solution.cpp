class Solution {
public:
    int string2int(string str) {
        int n = str.length();
        int ans = 0;
        int two = 1;
        for(int i = n-1 ; i >= 0 ; i--) {
            int bit = str[i] - '0';
            ans += (bit * two);
            two *= 2;
        }
        return ans;
    }

    string int2string(int a, int n) {
        int i = 0;
        string ans = "";
        while(a > 0) {
            ans = char('0' + (a % 2)) + ans;
            a /= 2;
            i++;
        }
        while(i < n) {
            ans = '0' + ans;
            i++;
        }
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> arr; int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            arr.push_back(string2int(nums[i]));
        }
        sort(arr.begin(), arr.end());
        if(arr[0] != 0) {
            return int2string(0, n);
        }
        for(int i = 1 ; i < n ; i++) {
            if(arr[i] != arr[i-1] + 1) {
                return int2string(arr[i-1]+1, n);
            }
        }
        return int2string(arr[n-1]+1, n);
    }
};
