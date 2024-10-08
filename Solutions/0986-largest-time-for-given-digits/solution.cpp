class Solution {
public:
    bool isValid(int A, int B, int C, int D) {
        if(A * 10 + B >= 24) return false;
        if(C * 10 + D >= 60) return false;
        
        return true;
    }
    
    string mini(string A, string B) {
        if(A == "") return B;
        if(B == "") return A;
        if(A > B) return A;
        return B;
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string ans = "";
        do {
            if(isValid(arr[0], arr[1], arr[2], arr[3])) {
                string B = "";
                B += char('0' + arr[0]);
                B += char('0' + arr[1]);
                B += ':';
                B += char('0' + arr[2]);
                B += char('0' + arr[3]);
                ans = mini(ans, B);
            }
        } while(next_permutation(arr.begin(), arr.end()));
        
        return ans;
    }
};
