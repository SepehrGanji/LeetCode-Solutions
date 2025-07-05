class Solution {
public:
    bool isValid(vector<int>& arr) {
        int h = (arr[0]*10) + arr[1];
        int m = (arr[2]*10) + arr[3];
        return h < 24 && m < 59;
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        string ans = "";
        sort(arr.begin(), arr.end());
        do {
            if(isValid(arr)) {
                string ten = "";
                ten += ('0' + arr[0]);
                ten += ('0' + arr[1]);
                ten += ':';
                ten += ('0' + arr[2]);
                ten += ('0' + arr[3]);
                if(ans == "") ans = ten;
                else ans = max(ans, ten);
            }
        } while (next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};
