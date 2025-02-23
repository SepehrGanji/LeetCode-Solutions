class Solution {
public:
    bool hasSameDigits(string s) {
        string mmd = s;
        cout << mmd.length() << endl;
        while(mmd.length() > 2) {
            string news = "";
            for(int i = 0 ; i < mmd.length() - 1 ; i++) {
                int a = (mmd[i] - '0');
                int b = (mmd[i+1] - '0');
                int c = (a + b) % 10;
                news += ('0' + c);
            }
            mmd = news;
            cout << mmd << endl;
        }
        return mmd[0] == mmd[1];
    }
};
