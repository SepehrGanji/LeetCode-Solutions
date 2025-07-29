class Solution {
public:
    vector<int> num2vec(int n) {
        vector<int> ans(30, 0);
        for(int i = 0 ; i < 30 ; i++) {
            ans[i] = n % 2;
            n /= 2;
        }
        return ans;
    }

    int vec2num(vector<int>& curr) {
        int ans = 0;
        int ali = 1;
        for(int i = 0 ; i < 30 ; i++) {
            ans += (ali * (curr[i] > 0));
            ali *= 2;
        }
        return ans;
    }

    void addnum(vector<int>& curr, int n) {
        for(int i = 0 ; i < 30 ; i++) {
            curr[i] += n % 2;
            n /= 2;
        }
    }

    void delnum(vector<int>& curr, int n) {
        for(int i = 0 ; i < 30 ; i++) {
            curr[i] -= n % 2;
            n /= 2;
        }
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size(), col = 0;
        vector<int> maxims;
        for(int i = n - 1 ; i >= 0 ; i--) {
            col |= nums[i];
            maxims.push_back(col);
        }
        reverse(maxims.begin(), maxims.end());
        vector<int> ans(n, 1);
        vector<int> current = num2vec(nums[n-1]);
        int j = n-1;
        for(int i = n - 2 ; i >= 0 ; i--) {
            addnum(current, nums[i]);
            do {
                delnum(current, nums[j]);
                j--;
            } while(vec2num(current) >= maxims[i] && j > i);
            if(vec2num(current) < maxims[i]) {
                j++;
                addnum(current, nums[j]);
            }
            ans[i] = j-i+1;
        }
        return ans;
    }
};
