class Solution {
public:
    int tribonacci(int n) {
        n++;
        vector<int> ans = {0, 1, 1};
        int i = 3;
        while(ans.size() < n) {
            int new_el = ans[i-1] + ans[i-2] + ans[i-3];
            ans.push_back(new_el);
            i++;
        }
        return ans[n-1];
    }
};
