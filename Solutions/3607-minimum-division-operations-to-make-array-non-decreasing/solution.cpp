class Solution {
public:
    int bega(int num) {
        int greatest = 1;
        for(int i = 2 ; i * i <= num ; i++) {
            if(num % i == 0) {
                greatest = max(max(i, num/i), greatest);
            }
        }
        return num/greatest;
    }

    int minOperations(vector<int>& nums) {
        int ans = 0; int n = nums.size();
        for(int i = n-1 ; i > 0 ; i--) {
            int el = nums[i], mmd = nums[i-1];
            bool redflag = false;
            while(mmd > el) {
                int new_mmd = bega(mmd);
                if(new_mmd == mmd) {
                    redflag = true;
                    break;
                }
                ans++;
                mmd = new_mmd;
            }
            if(redflag) {
                return -1;
            }
            nums[i-1] = mmd;
        }
        return ans;
    }
};
