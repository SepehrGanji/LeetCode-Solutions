class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) {
            return true;
        }
        for(int a = 0 ; a <= n - (k+k) ; a++) {
            bool mmd = true;
            for(int i = a+1 ; i < a + k ; i++) {
                if(nums[i] <= nums[i-1]) mmd = false;
            }
            cout << "a: " << a << "&mmd: " << mmd << endl;
            if(mmd == true) {
                for(int j = a+k+1 ; j < a+k+k ; j++) {
                    cout << "j: " << j << "&&arrj: " << nums[j] << endl;
                    if(nums[j] <= nums[j-1]) mmd = false;
                }
                //cout << "&mmd: " << mmd << endl;
                if(mmd) return true;
            }
        }
        return false;
    }
};
