class Solution {
public:
    vector<vector<int>> ans;
    int ka, en;

    void doIt(int i, vector<int> so_far) {
        if(so_far.size() == ka) {
            ans.push_back(so_far);
            return;
        }
        for(int ai = i ; ai <= en ; ai++) {
            so_far.push_back(ai);
            doIt(ai+1, so_far);
            so_far.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        ka = k; en = n;
        doIt(1, {});
        return ans;
    }
};
