class Solution {
public:
    vector<string> arr;

    void gen(int n, string curr) {
        if(curr.size() == n) {
            arr.push_back(curr);
            return;
        }

        for(char ch = 'a' ; ch < 'd' ; ch++) {
            if(curr.size() > 0 && curr.back() == ch) continue;
            gen(n, curr+ch);
        }
    }
    
    string getHappyString(int n, int k) {
        gen(n, "");
        if(arr.size() < k) return "";
        sort(arr.begin(), arr.end());
        return arr[k-1];    
    }
};
