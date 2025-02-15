class Solution {
public:
    bool helper(string num, int target, int idx) {
        int n = num.size();
        if(idx > n || target < 0) return false;
        if(idx == n) return target == 0;
        string mmd = "";
        for(int i = idx ; i < n ; i++) {
            mmd += num[i];
            int nunu = stoi(mmd);
            if(helper(num, target-nunu,i+1)) return true;
        }
        return false;
    }

    bool canDo(int i) {
        if(i == 1) return true;
        string num = to_string(i*i);
        return helper(num, i, 0);
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1 ; i <= n ; i++) {
            if(canDo(i)) ans += (i*i);
        }
        return ans;
    }
};
