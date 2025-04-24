class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zer = 0, on = 0, tw = 0;
        for(auto num: nums) {
            if(num == 0) zer++;
            else if(num == 1) on++;
            else tw++;
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            if(zer > 0) {
                nums[i] = 0;
                zer--;
            } else if(on > 0) {
                nums[i] = 1;
                on--;
            } else nums[i] = 2;
        }
    }
};
