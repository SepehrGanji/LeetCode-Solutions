class Solution {
public:
    // int slidei(int i, string s) {}
    int n;
    string str;

    int slidej(int j) {
        int cnt = 0;
        while(j >= 0) {
            if(str[j] == ']') cnt++;
            else {
                if(cnt > 0) cnt--;
                else {
                    str[j] = ']';
                    return j;
                }
            }
            j--;
        }
        return -1;
    }

    int minSwaps(string s) {
        int ans = 0;
        str = s;
        int cnt = 0, n = s.length();
        int j = n-1;
        for(int i = 0 ; i < j ; i++) {
            if(str[i] == '[') cnt++;
            else {
                if(cnt > 0) cnt--;
                else {
                    str[i] = '[';
                    j = slidej(j);
                    cnt++;
                    ans++;
                }
            }
        }
        return ans;
    }
};
